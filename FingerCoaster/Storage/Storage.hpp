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
    difficulty{0},numberOfPlayers(1),text(""){};

    void setDifficulty(unsigned newDifficulty);

    void setNumberOfPlayers(unsigned newNumberOfPlayer);
    
    unsigned getDifficulty() const;

    unsigned getNumberOfPlayers() const;

    void loadRandText();
    
    std::vector<std::string> formatTextForGame() const;

private:
    std::string pickRandomFile();

private:
    unsigned difficulty;
    unsigned numberOfPlayers;
    std::string text;

};

#endif