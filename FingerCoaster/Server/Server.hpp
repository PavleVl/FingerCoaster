#ifndef SERVER_HPP
#define SERVER_HPP

#include <sys/socket.h>
#include <exception>
#include <cerrno>
#include <cstring>
#include <string>

class Server{

public:

    inline Server(){}

    bool startServer();

private:
    int serverSocket;


};

#endif