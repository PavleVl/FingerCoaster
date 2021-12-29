#include <QApplication>
#include "Headers/gameEngine.h"
#include "Game/gamewindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameEngine* game = new GameEngine();
//    game->
//    game->show();
//   GameWindow* qmw = new GameWindow();
//   qmw->show();
    return a.exec();
}
