#include "server.h"

using namespace std;

int main() {

    int conn;
    char buffer[1024];
    ifstream fp ("b.txt");

    int res = 0;
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    list* l = new list();

    if (!(fp.is_open())) {
	    cout << "Cannot open file\n";
	    return -1;
	}
    if (!(l -> read(fp))) {
		fp.close();
        cout << "Cannot read file\n";
        return -2;
	}
    fp.close();
    cout << "Read from file.\n";

    // printf("%d\n",ss);
    struct sockaddr_in server_sockaddr, client_addr; // declare structure for server and client
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT); // htons - host-to-network
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr)) == -1) {
        perror("bind");
        delete l;
        close(conn);
        close(ss);
        return -3;
    }
    if(listen(ss, QUEUE) == -1) {
        perror("listen");
        delete l;
        close(conn);
        close(ss);
        return -4;
    }

    socklen_t length = sizeof(client_addr);
    /// Successful return of non-negative descriptor, error Return-1
    conn = accept(ss, (struct sockaddr*) &client_addr, &length);
    if( conn < 0 ) {
        perror("connect");
        delete l;
        close(conn);
        close(ss);
        return -3;
    }

    while (true) {

        memset(buffer, 0, sizeof(buffer)); // заполняем память нулями
        int len = recv(conn, buffer, sizeof(buffer), 0); // get data from socket and put them to buffer
        for (int j=0; buffer[j]; j++) {
          if (buffer[j] == '\n') {
            cout << "\n";
            buffer[j] = 0;
            break;
          }
        }
        cout << "Got command: " << buffer << "\n";

        command *c = new command(); // initialize new object: command
        if ((c -> init(buffer)) < 0) {
            cout << "Syntax error!\n";
        }
        res = c -> apply( l );
        delete c;

        if (res) break;
        // sprintf(answer, "Command \"%s\" is executed.", buffer);
        send(conn, buffer, len , 0);
    }
    delete l;
    close(conn);
    close(ss);
    return 0;
}