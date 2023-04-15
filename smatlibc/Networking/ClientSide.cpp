#include "ClientSide.hpp"
#include <stdlib.h>
#include <arpa/inet.h>

hde::ClientSocket::ClientSocket(int dom, int serv, int prot, int pt, const char * inter):SimpleSocket(dom, serv, prot, pt)
{
    if(inet_pton(domain, inter, &address.sin_addr) <= 0)
    {
        perror("In inet pton");
        exit(EXIT_FAILURE);
    }
    connect_to_network();

}
void hde::ClientSocket::connect_to_network()
{   if ((sock = socket(domain, service, protocol))<0)
    {
        perror("In Socket");
        exit(EXIT_FAILURE);
    }
    if (connect(sock, paddress, (socklen_t)addrlen) < 0)
    {   printf("%d", sock);
        perror("In Connect");
        exit(EXIT_FAILURE);
    }
}
int * hde::ClientSocket::get_sock(){
    return &sock;
}