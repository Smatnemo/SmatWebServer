#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <netinet/in.h> // we get the struct sockaddr_in from this header file

namespace hde
{
class SimpleSocket
    {
    protected:
        struct sockaddr_in address;
        int sock;
        int addrlen;
        int service;
        int protocol;
        int domain;
        struct sockaddr* paddress;

    public:
        SimpleSocket(int, int, int, int);
        virtual void connect_to_network() = 0;//This makes this class an abstract class using this pure virtual function
    };
// It is a very good idea to make the parameter names different from the variable names.
// Or initialize the data members of the class in a different way A::A(int val):var(val)
// the val value is the parameter and the var variable is a data member.
// var can also be a function such as when the parent constructor is initialized using the parameters from the derived constructor 

SimpleSocket::SimpleSocket(int dom, int serv, int prot, int pt)
{
    address.sin_family = dom;
    address.sin_port = htons(pt);
    addrlen = sizeof(address);
    paddress = (struct sockaddr *)&address;
    service = serv;
    protocol = prot;
    domain = dom;
}

}
#endif /* SimpleSocket_hpp*/

