#include "client.h"

using namespace std;

int main()
{
    int i, j, k, buff_len = 1024;
    const char* file = "commands2.txt";
    ifstream fp ("b.txt");

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

    char sendbuf[buff_len];
    char recvbuf[buff_len];

    // open file
    if (!(fp.is_open())) {
	    cout << "Cannot open file\n";
	    return -1;
	}

    while (fp.getline(sendbuf, buff_len)) {
        for (j = 0; sendbuf[j]; j++) {
            if (sendbuf[j] == '\n') {
                sendbuf[j] = 0;
                break;
            }
        }
        cout << "Request to server: " << sendbuf << "\n";
        send(sock_cli, sendbuf, strlen(sendbuf), 0); /// Send
        recv(sock_cli, recvbuf, sizeof(recvbuf), 0); /// Receiving
        cout << "Answer from server: " << recvbuf << "\n";

        memset(sendbuf, 0, sizeof(sendbuf));
        memset(recvbuf, 0, sizeof(recvbuf));        
    }
    close(sock_cli);
    return 0;
}