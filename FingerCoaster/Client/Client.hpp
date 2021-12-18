#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <sys/socket.h>
#include <cerrno>
#include <stdexcept>

class Client{
    
public:

    inline Client(){
        connectToServer();
    };

    void connectToServer();


private:
    int socketFd;


};

#endif 