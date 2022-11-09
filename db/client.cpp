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

#include "command.h"

#define MYPORT  7000
#define BUF_LEN 1024

int main()
{
    int i, j, k;
    const char* file = "commands2.txt";

    FILE * fp;
    /// Define sockfd
    int sock_cli = socket(AF_INET, SOCK_STREAM, 0);
    /// Define sockaddr_in
    struct sockaddr_in servaddr;
    // memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(MYPORT);  /// Server Port
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  /// server ip

    //Connect to the server, successfully return 0, error return - 1
    if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char sendbuf[BUF_LEN];
    char recvbuf[BUF_LEN];

    // open file
    if (!(fp = fopen(file,"r"))) {
	    printf("Cannot open file\n");
	    return -1;
	}

    while (fgets(sendbuf, BUF_LEN, fp)) {
        for (j = 0; sendbuf[j]; j++) {
            if (sendbuf[j] == '\n') {
                sendbuf[j] = 0;
                break;
            }
        }
        printf("%s\n", sendbuf);
        send(sock_cli, sendbuf, strlen(sendbuf), 0); /// Send
        recv(sock_cli, recvbuf, sizeof(recvbuf),0); /// Receiving
        fputs(recvbuf, stdout);
        memset(sendbuf, 0, sizeof(sendbuf));
        memset(recvbuf, 0, sizeof(recvbuf));
        scanf("%d", &k);
    }
    close(sock_cli);
    return 0;
}