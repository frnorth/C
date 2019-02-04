#include "tcp_net_socket.h"
int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("usafe:./clienttcp ip port\n");
        exit(-1);
    }
    int sfd = tcp_connect(argv[1], atoi(argv[2]));
    char buf[512] = {0};
    send(sfd, "Hello World!\nAnd, my name is client", 50, 0);
    recv(sfd, buf, sizeof(buf), 0);
    puts(buf);
    close(sfd);
}
