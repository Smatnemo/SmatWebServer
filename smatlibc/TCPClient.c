#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0; long valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n socket creation Error");
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
   
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) // if this is successful it will return 1 and store the binary value at the address specified
    {
        printf("\nInvalid address/ Address not supported");
        return -1;
    }
    // volatile unsigned int *p = (volatile unsigned int *)&serv_addr.sin_addr;

    // printf("%u\n", *p);
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
    return 0;
}