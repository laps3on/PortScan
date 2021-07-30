#include <stdio.h>        // printf(), perror()
#include <sys/types.h>    // AF_INET, SOCK_STREAM
#include <sys/socket.h>   // socket(), connect()
#include <netinet/in.h>   // struct sockaddr_in
#include <arpa/inet.h>    // htons(), inet_addr()
#include <unistd.h>       // close()

int main(int argc, char*argv[])
{
        int msocket;
        int con;
        int init = 0;
        int end = 65535;
        int port;
        char *destiny;
        destiny = argv[1];

        struct sockaddr_in target;

        for(port=init;port<end;port++)
        {
        msocket  = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(destiny);

        con = connect(msocket, (struct sockaddr *)&target, sizeof target);

        if(con == 0)
        {
                printf("Port %d - STATUS[OPEN]\n", port);
                close(msocket);
                close(con);
        }else{
                close(msocket);
                close(con);
        }
        }
}