#ifndef CLIENTSIDE_HPP
#define CLIENTSIDE_HPP

#include <stdio.h>
#include "SimpleSocket.hpp"
namespace hde
{
    class ClientSocket: public SimpleSocket
    {
        public:
        ClientSocket(int dom, int serv, int prot, int pt, const char *);
        void connect_to_network();
        int *get_sock();
    };
}

#endif /*CLIENTSIDE_HPP*/