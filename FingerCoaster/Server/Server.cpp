#include "Server.hpp"

#define SERVER_PORT 8080

Server::Server(QObject* parent) : QTcpServer(parent),inGame(false){
    serverStorage = new Storage();
    serverStorage->loadText(true);
    serverStorage->setNumberOfPlayers(3);
    ScoreboardBackend sc;
    std::string sufix = "(host)";
    myUsername = QString::fromStdString(sc.giveUsername()) + QString::fromStdString(sufix);
    usernames.insert(-1,myUsername);
}

auto Server::getServerStorage()const -> Storage*{
    return serverStorage;
}

void Server::startServer(){
    if(!this->listen(QHostAddress::Any,SERVER_PORT)){
        std::cout << "Server could not start" << std::endl;
    }
    else{
        std::cout << "Server has been started " << this->serverAddress().toString().toStdString() << std::endl;
    }
}

auto Server::numOfClients() const -> int{
    return threads.size();
}

void Server::setStorageDifficulty(unsigned difficulty){
    serverStorage->setDifficulty(difficulty);
}

void Server::setStorageMaxPlayers(unsigned maxPlayers){
    serverStorage->setNumberOfPlayers(maxPlayers);
}

void Server::incomingConnection(qintptr socketFd){
    if((unsigned(threads.size()) < serverStorage->getNumberOfPlayers()) && !inGame){
        auto* thread = new Thread(socketFd,this);
        threads.insert(socketFd,thread);

        connect(thread,SIGNAL(setClientsUsername(qintptr,QString)),this,SLOT(setClientsUsername(qintptr,QString)),Qt::DirectConnection);
        connect(thread,SIGNAL(deleteThread(qintptr)),this,SLOT(deleteThread(qintptr)),Qt::DirectConnection);
        //connect(thread,SIGNAL(updateClientsProgress(qintptr,unsigned)),this,SLOT(updateClientsGameProgress(qintptr,unsigned)),Qt::DirectConnection);
        connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),Qt::DirectConnection);

        std::cout << "Accepted the socket ";
        thread->start();

        std::string choosenFile = "text:" + serverStorage->getChoosenFile();
        QByteArray byteBuff(choosenFile.c_str(),choosenFile.length());
        emit sendMessage(byteBuff,socketFd);

    }
    else if(inGame){
        QTcpSocket rejectedSocket;
        rejectedSocket.setSocketDescriptor(socketFd);
        rejectedSocket.write("SERVER_IN_GAME");
        rejectedSocket.close();
    }
    else{
        QTcpSocket rejectedSocket;
        rejectedSocket.setSocketDescriptor(socketFd);
        rejectedSocket.write("SERVER_IS_FULL");
        rejectedSocket.close();
    }

}

void Server::setGameStarted(bool gameStartedFlag){
    inGame = gameStartedFlag;
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
        std::string sufix = "host";
        if(it.value().contains(QString::fromStdString(sufix)))
            continue;

        usernamesBuffWithoutHost.push_back(it.value().first(it.value().size()));
        it++;
    }

    if(usernamesBuff.size() > 0)
        emit rewriteLobbyList(&usernamesBuffWithoutHost);
}

void Server::blockConnections(){
    std::cout << "Server is blocking connections!" << std::endl;
    //this->pauseAccepting();
}

void Server::broadcastUsernames(){
    std::string outputMsg = "usernamesList:";
    auto it = usernames.begin();
    while(it != usernames.end()){
        outputMsg += it.value().toStdString() + ":";
        it++;
    }

    QByteArray byteBuff(outputMsg.c_str(),outputMsg.length()-1);
    QString buff = QString::fromUtf8(byteBuff);
    emit sendMessage(buff.toUtf8(),0);
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

void Server::softCloseTheServer(){
    if(threads.size() > 0){
        emit softEndConnection();

        auto it = threads.begin();
        while(it != threads.end())
            it.value()->deleteLater();

        this->close();
        emit serverShutdown();
    }
    emit serverShutdown();
}

void Server::initializeGame(){

    QVector<QString> usernamesBuff;

    auto it = usernames.begin();
    QPair<qintptr,QString> keyPair;
    while(it != usernames.end()){
        usernamesBuff.push_back(it.value());

        keyPair = qMakePair(it.key(),it.value());
        progress.insert(keyPair,0);

        it++;
    }

    emit populateGame(&usernamesBuff);
}

void Server::setMyProgress(unsigned curProgress){
    std::cout << "Current server progress " << curProgress << std::endl;
    emit sendMessage("HELLO FROM SERVER",0);
    QPair<qintptr,QString> serverPair = qMakePair(-1,myUsername);
    progress.insert(serverPair,curProgress);
}

void Server::startGameForClients(){
    emit sendMessage("startGame",0);
}

void Server::updateClientsGameProgress(qintptr socketFd,unsigned curClientProgress){
    std::cout << "Usao sam u update game progress" << socketFd << " " << curClientProgress << std::endl;
    QPair<qintptr,QString> clientKey = qMakePair(socketFd,usernames.find(socketFd).value());
    progress.insert(clientKey,curClientProgress);
    broadcastProgress();
    changeGameProgress();
}

void Server::broadcastProgress(){

    std::string buff = "gameProgress:";
    QString msgBuff = QString::fromStdString(buff);
    auto it = progress.begin();
    while(it != progress.end()){
        msgBuff += it.key().second + QString::fromStdString("-") + QString::number(it.value()) +
                QString::fromStdString(":");

        it++;
    }
    //std::cout << "Posalo listu progressa " << msgBuff.toStdString() << std::endl;
    QByteArray byteBuff(msgBuff.toStdString().c_str(),msgBuff.length()-1);
    emit sendMessage(QString::fromStdString("PROBA").toUtf8(),0);
}

void Server::changeGameProgress(){
    std::cout << "Usao sam u change game progress" << std::endl;
    QVector<unsigned> gameProgress;
    auto it = progress.begin();
    while(it != progress.end()){
        gameProgress.push_back(it.value());
        it++;
    }

    std::cout << "Emitovao" << std::endl;
    emit changeCurGameProgress(&gameProgress);
}
