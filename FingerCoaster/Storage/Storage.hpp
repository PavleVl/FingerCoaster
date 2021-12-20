#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <sstream>

class Storage{

public:
    inline Storage():
    difficulty{0},numberOfPlayers(1),text(""),choosenFile(""){};

    void setDifficulty(unsigned newDifficulty);

    void setNumberOfPlayers(unsigned newNumberOfPlayer);
    
    void setChoosenFIle(std::string newChoosenFile);

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
