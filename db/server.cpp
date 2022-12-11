#include "server.h"

using namespace std;

Server::Server(list* l) {
    ss = socket(AF_INET, SOCK_STREAM, 0);
    this->l = l;
    server_sockaddr.sin_family = AF_INET; // default value (always)
    server_sockaddr.sin_port = htons(PORT); // htons - host-to-network
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY); // fix constant
}
Server::~Server() {
    close(ss);
    delete l;
}

int main() {

    struct sockaddr_in client_addr {};
    int conn;
    char buffer[1024];
    ifstream fp ("b.txt");

    int res = 0;
    
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

    Server server(l);

    if (bind(server.ss, (struct sockaddr* ) &server.server_sockaddr, sizeof(server.server_sockaddr)) == -1) {
        perror("bind");
        return -3;
    }
    if(listen(server.ss, QUEUE) == -1) {
        perror("listen");
        return -4;
    }    
    if(conn<0) {
        perror("connect");
        return -3;
    }

    socklen_t length = sizeof(client_addr);
    conn = accept(server.ss, (struct sockaddr*) &client_addr, &length);

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
        send(conn, buffer, len , 0);
    }
    close(conn);
    return 0;
}