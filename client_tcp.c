#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define PORT 9600

int main(int argc, char *argv[])
{
    int             s_discriptor;
    int             cnx_r;
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
    frlen = sizeof(add);
    //add.sin_zero = [0];

    if((s_discriptor = socket(PF_INET, SOCK_DGRAM, 0)) == -1)
        return (0);
    if((cnx_r = connect(s_discriptor, (struct sockaddr *)&add, sizeof(add))) == -1)
        return (0);
     
    buffer = malloc(sizeof(char) * 1000);
    scanf("%s", buffer);

    reed = read(s_discriptor, buffer, sizeof(buffer));
    if (reed== -1)
            return (0);

    write(1, &buffer, sizeof(buffer));
     //close();

}
    // write(1, ..., sizeof(...));
    // close();
