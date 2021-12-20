#include <QCoreApplication>
#include "Server.hpp"
#include "../../Storage/Storage.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server ourServer;
    ourServer.startServer();


    return a.exec();
}
