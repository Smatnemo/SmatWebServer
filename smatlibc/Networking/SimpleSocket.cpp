#include "SimpleSocket.hpp"
#include <stdlib.h>

// This file implements a simple socket for TCP/IP. The int domain accepts AF_INET.
// The int service is for the type parameter which specifies how the communication will occur.
// For a TCP connection the type SOCK_STREAM is used, and for UDP connection the type SOCK_DGRAM is used
// AF_INET refers to Address from the internet and it requires a pair of (host, port) where the host can
// either be a URL of some particulart website or its address and the port number is an integer.
// AF in "AF_INET" stands for Address Family 
// PF in "PF_INET" stands for Protocol family

// There are three types of sockets
// 1. Stream Sockets: SOCK_STREAM
// 2. Datagram Sockets: SOCK_STREAM
// 3. RAW SOCKET: SOCK_RAW


// Default constructor
// hde::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
// {
//     address.sin_family = domain;
//     address.sin_port = htons(port);
//     addrlen = sizeof(address);
//     // paddress = (struct sockaddr *)&address;
//     service = service;
//     protocol = protocol;
//     domain = domain;
// }

