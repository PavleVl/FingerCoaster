#include <QApplication>
#include "../Headers/gameEngine.h"
#include "../Headers/gameDialog.h"
auto main(int argc, char *argv[]) -> int
{
    QApplication a(argc, argv);
    auto* game = new GameEngine();
    game->show();
//    GameDialog* gd = new GameDialog();
//    gd->setModal(true);
//    gd->show();
    return a.exec();
}
