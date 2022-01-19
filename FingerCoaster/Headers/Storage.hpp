#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class Storage {
 public:
  inline Storage()
      : difficulty{0}, numberOfPlayers(1), choosenFile(""), text(""){};

  void setDifficulty(unsigned newDifficulty);

  void setNumberOfPlayers(unsigned newNumberOfPlayer);

  void setChoosenFile(std::string newChoosenFile);

  unsigned getDifficulty() const;

  unsigned getNumberOfPlayers() const;

  std::string getChoosenFile() const;

  void loadText(bool randomTextFlag);

  std::vector<std::string> formatTextForGame() const;

 private:
  void pickRandomFile();

 private:
  unsigned difficulty;
  unsigned numberOfPlayers;
  std::string choosenFile;
  std::string text;
};

#endif
