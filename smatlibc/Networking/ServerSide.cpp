#include "ServerSide.hpp"


hde::ServerSocket::ServerSocket(int dom, int serv, int prot, int pt, u_long inter): SimpleSocket(dom, serv, prot, pt)
{
    address.sin_addr.s_addr = inter;

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    connect_to_network();

}
void hde::ServerSocket::connect_to_network(){
    if ( (sock = socket(domain, service, protocol)) < 0)
    { 
        perror("In socket");
        exit(EXIT_FAILURE);
    }
    if(bind(sock, paddress, addrlen)<0){
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if(listen(sock, 10))
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    printf("\n ++++++++Waiting for Network Connection+++++++++++++\n");
    
}
int * hde::ServerSocket::accept_connection(){
    if ((new_socket = accept(sock, paddress, (socklen_t*)&addrlen)) < 0)
    {
        perror("In new socket");
    }
    return get_pnew_socket();
}

int * hde::ServerSocket::get_pnew_socket()
{
    return &new_socket;
}
int hde::ServerSocket::get_sock(){
    return sock;
}
struct sockaddr * hde::ServerSocket::get_paddress(){
    return paddress;
}
int hde::ServerSocket::get_domain(){
    return domain;
}
socklen_t* hde::ServerSocket::get_address(){
    return (socklen_t *)&addrlen;
}