#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <thread>
#include <iostream>

#include "command.h"

#define PORT 7000
#define QUEUE 20
#define BUFFLEN 1024

int conn;
void thread_task() {
}

int main() {

    //printf("%d\n",AF_INET);
    //printf("%d\n",SOCK_STREAM);

    const char* file = "b.txt";
    char answer[BUFFLEN];
    FILE * fp;

    int i, j, k, res = 0, ss = socket(AF_INET, SOCK_STREAM, 0);
    char buffer[BUFFLEN];
    list* l = new list();

    if (!(fp = fopen(file,"r"))) {
	    printf("Cannot open file\n");
	    return -1;
	}
    if (!(l -> read(fp))) {
		fclose(fp);
        printf("Cannot read file\n");
        return -2;
	}
    fclose(fp);

    // printf("%d\n",ss);
    struct sockaddr_in server_sockaddr, client_addr; // declare structure for server and client

    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT); // htons - host-to-network
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }
    if(listen(ss, QUEUE) == -1) {
        perror("listen");
        exit(1);
    }

    socklen_t length = sizeof(client_addr);
    /// Successful return of non-negative descriptor, error Return-1
    conn = accept(ss, (struct sockaddr*) &client_addr, &length);
    if( conn < 0 ) {
        perror("connect");
        exit(1);
    }

    //Create another thread
    //std::thread t(thread_task);
    //t.join();
    //char buf[1024];
    //Main thread
    // scanf("%d", &k);
    while (true) {

        // memset(buf, 0 ,sizeof(buf));
        // if(fgets(buf, sizeof(buf),stdin) != NULL) {
        //     send(conn, buf, sizeof(buf), 0);    
        // }

        memset(buffer, 0, sizeof(buffer)); // заполняем память нулями
        int len = recv(conn, buffer, sizeof(buffer), 0); // get data from socket and put them to buffer
        for (j=0; buffer[j]; j++) {
          if (buffer[j] == '\n') {
            printf("%c\n", buffer[j]);
            buffer[j] = 0;
            break;
          }
        }
        printf("Got command: %s\n", buffer);

        command *c = new command(); // initialize new object: command
        if ((c -> init(buffer)) < 0) {
            printf("Syntax error!\n");
        }
        res = c -> apply( l );
        delete c;

        if (res) break;
        sprintf(answer, "Command \"%s\" is executed.", buffer);
        send(conn, answer, len , 0);
    }
    delete l;
    close(conn);
    close(ss);
    return 0;
}