#include <QCoreApplication>
#include "Client.hpp"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client* c = new Client("Vlado");
    return a.exec();
}
