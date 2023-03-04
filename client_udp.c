#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define PORT 9600

// struct in_addr{
//     u_long  s_addr;
// };

// struct sockadddr_in{
//     u_short         sin_family;
//     u_short         sin_port;
//     struct in_addr  sin_addr;
//     char            sin_zero[8];
// };

// int socket(int domain, int type, int protocol){

// }

int main(int argc, char *argv[])
{
    int             s_discriptor;
    int             bind_r;
    int             addIp;
    char            *buffer;
    int             reed;
    int             frlen;
    struct sockaddr_in    add;

    printf("entree l'addresse ip du serveur");
    scanf("%d", addIp);
    add.sin_family = PF_INET;
    add.sin_port = PORT; 
    add.sin_addr.s_addr = addIp;
    //add.sin_zero = [0];
    if((s_discriptor = socket(PF_INET, SOCK_DGRAM, 0)) == -1)
        return (0);
    if((bind_r = bind(s_discriptor, (struct sockaddr *)&add, sizeof(add))) == -1)
        return (0);
    frlen = sizeof(add); 
    buffer = malloc(sizeof(char) * 1000);
    scanf("%s", buffer);
    reed = sendto(s_discriptor, buffer, sizeof(buffer), 0, (struct sockaddr *)&add, &frlen );
    if (reed== SOCKET_ERROR)
            return (0);
}
    // write(1, ..., sizeof(...));
    // close();

