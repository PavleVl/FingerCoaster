#include <QApplication>
#include "Headers/gameEngine.h"
#include "Game/gameDialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameEngine* game = new GameEngine();
    game->show();
//    GameDialog* gd = new GameDialog();
//    gd->setModal(true);
//    gd->show();
    return a.exec();
}
