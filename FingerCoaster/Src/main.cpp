#include <QApplication>
#include "../Headers/gameDialog.h"
#include "../Headers/gameEngine.h"
auto main(int argc, char* argv[]) -> int {
  QApplication a(argc, argv);
  auto* game = new GameEngine();
  game->show();
  //    GameDialog* gd = new GameDialog();
  //    gd->setModal(true);
  //    gd->show();
  return a.exec();
}
