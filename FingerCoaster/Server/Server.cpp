
#include "Server.hpp"
#include <arpa/inet.h>

bool Server::startServer(){

    int socketfd = socket(AF_INET,SOCK_DGRAM,0);

    if(socketfd == -1){
        throw  std::string("Socket creating failed") + std::strerror(errno);
        return false;
    }

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET,"0.0.0.0",&hint.sin_addr);

    if(bind(socketfd,AF_INET,(sockadr*)&hint,sizeof(hint)) == -1){
        //TODO ERROR HANDLING
        //SERVER CAN'T BIND TO IP PORT
    }

    //3 JE MAX KONEKCIJA
    if(listen(socketfd,3) == -1){
        //TODO ERROR HANDLING
        //SERVER CANT LISTEN
    }

    


    return true;
}