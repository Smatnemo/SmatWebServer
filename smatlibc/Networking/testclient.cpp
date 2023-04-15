#include "ClientSide.cpp"
#include <string.h>

#include <unistd.h>


using namespace std;
using namespace hde;

#define PORT 8080
int main () {
    const char * hello = "Hello from the Client";
    char buffer[1024] = {0};

    ClientSocket client(AF_INET, SOCK_STREAM, 0, PORT, "127.0.0.1");
    int *psock = client.get_sock();


    send(*psock, hello, strlen(hello), 0);
    printf("Hello message sent!");
    int valread = read(*psock, buffer, 1024);
    printf("%s", buffer);

    return 0;
}