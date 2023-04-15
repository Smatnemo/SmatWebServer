#include <stdio.h>
#include <iostream>
// #include "ServerSocket.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ServerSide.cpp"
// #include "ClientSide.cpp"
#define PORT 8080

using namespace std;
using namespace hde;




// Definition of declared functions

// ServerSocket::~ServerSocket()
// {
//     close(new_socket);
// }



int main(){
    const char *hello = "Hello from the Server";
    // ServerSocket* pserver = new ServerSocket(AF_INET, SOCK_STREAM, 0, PORT, INADDR_ANY);
    ServerSocket server(AF_INET, SOCK_STREAM, 0, PORT, INADDR_ANY);
    // ClientSocket client(AF_INET, SOCK_STREAM, 0, PORT, "127.0.0.1");

    while(true){
        int *pnew_socket = server.accept_connection();
        
        // int *pnew_socket = pserver->accept_connection();      
        // int new_socket = accept(pserver->get_sock(), pserver->get_paddress(), pserver->get_address());
        // printf("%d", new_socket);


        char buffer[30000] = {0};
        int valread = read(*pnew_socket, buffer, 30000);
        printf("%s\n", buffer);
        write(*pnew_socket, hello, strlen(hello));
        close(*pnew_socket);
        printf("\n++++++++++Waiting For Connection+++++++++++++\n");
    }
    // delete pserver;

    
    

    return 0;
}