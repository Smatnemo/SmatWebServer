About----------------------------------------------------------------------------------------------

I just want it to be known that I am not a fan of web development at the time of writing this README.md..
However I have done this project to practice skills in C++ and C. The first implementation in C was from a source on medium. Check https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa. Credit to Screw Everything for the TCPServer.c and 
TCPClient.c implementation.

I thought it was brilliant, simple and straight forward.
I took his implementation and turned it into three classes in C++. A simple Socket Parent and two children: Client and Server Sockets. If you wish to use this repo, feel free to. I am just an enthusiast.

How to use-------------------------------------------------------------------------------------------
There are two translation units named test.cpp and testclient.cpp. test.cpp implements the use of ServerSide.cpp which carries a class ServerSocket. The Server
Socket is a derivative of the class SimpleSocket that implements a simple Server socket that listens and accepts a request from a client. Running the translation unit should create a socket and print "++++++++Waiting for Network connection++++++++++++++++++++".

The other translation unit testclient.cpp is used to implement and demonstrate the use ClientSocket in ClientSide.hpp. ClientSocket is also a child of Simple Socket. Since address structure required for both Server and Client Sockets have similar structures, it makes sense for their initialization to be in the same parent class.

Running testclient.cpp sends a request to the server and the server responds with a message
"Hello message sent!"
"Hello from Server" 

The server in turn prints out
"Hello from the client"

and
"+++++++++++++++Waiting For Connection++++++++++++++++++




The plan----------------------------------------------------------------------------------------------------
The plan is to build a TCP/IP webserver that can run on an embedded device that is capable of multiple threads. I am yet to formulate the full plan but I am sure it will be exciting.



