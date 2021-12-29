#include "Server.hpp"


#define SERVER_PORT 8080

Server::Server(QObject* parent) : QTcpServer(parent){
    serverStorage = new Storage();
    serverStorage->loadText(true);
    serverStorage->setNumberOfPlayers(3);

    ScoreboardBackend sc;
    usernames.insert(-1,QString::fromStdString(sc.giveUsername()) + "(host)");
}

void Server::startServer(){
    if(!this->listen(QHostAddress::Any,SERVER_PORT)){
        std::cout << "Server could not start" << std::endl;
    }
    else{
        std::cout << "Server has been started " << this->serverAddress().toString().toStdString() << std::endl;
    }
}

int Server::numOfClients() const{
    return threads.size();
}

void Server::setStorageDifficulty(unsigned difficulty){
    serverStorage->setDifficulty(difficulty);
}

void Server::setStorageMaxPlayers(unsigned maxPlayers){
    serverStorage->setNumberOfPlayers(maxPlayers);
}

void Server::incomingConnection(qintptr socketFd){
    if(unsigned(threads.size()) < serverStorage->getNumberOfPlayers()){
        Thread* thread = new Thread(socketFd,this);
        threads.insert(socketFd,thread);

        connect(thread,SIGNAL(setClientsUsername(qintptr,QString)),this,SLOT(setClientsUsername(qintptr,QString)),Qt::DirectConnection);
        connect(thread,SIGNAL(deleteThread(qintptr)),this,SLOT(deleteThread(qintptr)),Qt::DirectConnection);
        connect(thread,SIGNAL(finished()), thread,SLOT(deleteLater()),Qt::DirectConnection);

        std::cout << "Accepted the socket ";
        thread->start();

        std::string choosenFile = "text:" + serverStorage->getChoosenFile();
        QByteArray byteBuff(choosenFile.c_str(),choosenFile.length());
        emit sendMessage(byteBuff,socketFd);

    }
    else{
        QTcpSocket *rejectedSocket = new QTcpSocket();
        rejectedSocket->setSocketDescriptor(socketFd);
        rejectedSocket->write("MAX_LIMIT_ABORT");
        rejectedSocket->close();
        //TODO
        //deletelater blocks close
        //rejectedSocket->deleteLater();
    }
}

//Slots:
//TOTEST
//I'm not sure if this part will break because of threads
void Server::setClientsUsername(qintptr clientSocketFd,QString username){
    std::cout << "Usao sam u setClient!";

    emit updateLobbyList(username);
    usernames.insert(clientSocketFd,username);

    std::cout << "List of usernames: " << std::endl;
    auto it = usernames.begin();
    while(it != usernames.end()){
        std::cout << it.value().toStdString() << " ";
        it++;
    }


    broadcastUsernames();
}

void Server::deleteThread(qintptr socketFd){
    std::cout << "Thread deleted" << std::endl;

    threads.remove(socketFd);
    usernames.remove(socketFd);

    QVector<QString> usernamesBuff;
    auto it = usernames.begin();
    while(it != usernames.end()){
        usernamesBuff.push_back(it.value().first(it.value().size()));
        it++;
    }
    if(usernamesBuff.size() > 1)
        broadcastUsernames();

    QVector<QString> usernamesBuffWithoutHost;
    while(it != usernames.end()){
        if(it.value().contains("(host)"))
            continue;

        usernamesBuffWithoutHost.push_back(it.value().first(it.value().size()));
        it++;
    }

    if(usernamesBuff.size() > 0)
        emit rewriteLobbyList(&usernamesBuffWithoutHost);
}

void Server::blockConnections(){
    std::cout << "Server is blocking connections!" << std::endl;
    this->pauseAccepting();
}

void Server::broadcastUsernames(){
    std::string outputMsg = "usernamesList:";
    auto it = usernames.begin();
    while(it != usernames.end()){
        outputMsg += it.value().toStdString() + ":";
        it++;
    }

    QByteArray byteBuff(outputMsg.c_str(),outputMsg.length()-1);
    emit sendMessage(byteBuff,0);
}

void Server::forceCloseTheServer(){
    if(threads.size() > 0){

        emit endConnection();

        auto it = threads.begin();
        while(it != threads.end())
            it.value()->deleteLater();

        this->close();
        emit serverShutdown();
    }
    emit serverShutdown();
}
