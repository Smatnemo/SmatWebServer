#ifndef SERVERSIDE_HPP
#define SERVERSIDE_HPP
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#include "SimpleSocket.hpp"


namespace hde 
{
// Class declarations
class ServerSocket: public SimpleSocket
{
private:
int new_socket;
public:
ServerSocket(int dom, int serv, int prot, int pt, u_long inter);
void connect_to_network();
int * accept_connection();
int * get_pnew_socket();
int get_sock();
struct sockaddr * get_paddress();
int get_domain();
socklen_t* get_address();
};
}
#endif /*SERVERSIDE_HPP*/