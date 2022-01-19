#include "../Headers/game.h"

Game::Game(std::string choosenText, QObject* parent) : QObject{parent} {
  Storage ourStorage;
  ourStorage.setChoosenFile(choosenText);
  ourStorage.loadText(false);

  gameText = ourStorage.formatTextForGame();
}
