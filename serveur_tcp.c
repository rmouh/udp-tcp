/*code serveur */

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
    int             new_s_discriptor;
    int             bind_r;
    char            *buffer;
    int             returned;
    int             called_len;
    struct sockaddr_in    add;
    /*
        initialisation de la structure
                                         */ 
    add.sin_family = PF_INET;
    add.sin_port = PORT; 
    add.sin_addr.s_addr = INADDR_ANY;
    called_len = sizeof(add);
    //add.sin_zero = [0];
 /*
        creation de la socket + lecture
                                         */ 
    if((s_discriptor = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        return (0);
    if((bind_r = bind(s_discriptor, (struct sockaddr *)&add, sizeof(add))) == -1)
        return (0);
     
    /*
        creation du buffer 
                             */ 
    buffer = malloc(sizeof(char) * 1000);

    /*
        algo 
                */ 
    if (listen(s_discriptor,10) == 0)
    {
        new_s_discriptor = socket(PF_INET, SOCK_STREAM, 0);
        if ((accept(s_discriptor,(struct sockaddr*)&add, &called_len) == INVALID_SOCKET))
            return (0);
        returned = read(s_discriptor, buffer, sizeof(buffer));
        if (returned == -1)
            return (0);
        write(1, &buffer, sizeof(buffer));
     //close();

    }


}