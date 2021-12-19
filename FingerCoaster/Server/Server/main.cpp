#include <QCoreApplication>
#include "Server.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server ourServer;
    ourServer.startServer();

    ourServer.waitForNewConnection(3000);
    ourServer.waitForNewConnection(3000);
    ourServer.broadcast("Hello!");

    return a.exec();
}
