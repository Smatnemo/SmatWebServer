#include <stdio.h>
#include <string.h> // includes the memset header file
#include <sys/socket.h> // includes socket
#include <netinet/in.h> // includes the sockaddr structure
#include <stdlib.h> // includes exit(EXIT_FAILURE)
#include <unistd.h> // includes 


#define PORT 8080



int main(int argc, char const *argv[]){
    // put all of these in a class in cpp
    int server_fd, new_socket; long valread;
    struct sockaddr_in address; int addrlen = sizeof(address);

    char *hello = "Hello from server";


    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }
    // printf("%d", server_fd);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;// This is the address used when you don't want to bind a socket to any particular address.
    address.sin_port = htons(PORT);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);// memset is used to fill the memory location starting from sin_zero which is an array with '\0' so as to prevent undefined behaviour


    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10)<0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        printf("\n++++++++++Waiting for new connection++++++++\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        // printf("%d", new_socket);

        char buffer[30000] = {0}; // always fill a buffer or a variable up so as to prevent undefinde behaviour
        valread = read(new_socket, buffer, 30000); // from unistd.h attempts to read the 30000 bytes from the file descriptor, new socket starting at address buffer(pointer to the first character)
        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello)); 
        printf("----------------Hello Message Sent-------------------\n");
        close(new_socket);
    }
    return 0;

}