#include <QCoreApplication>
#include <QDebug>
#include "Client.hpp"
int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);
  Client* c = new Client("Vlado");
  return a.exec();
}
