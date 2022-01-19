#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "../Headers/Storage.hpp"
#include "../Headers/Result.hpp"
#include <vector>

//TOFIX
//For the sake of testing this class is currently
//being run from constuctor of GameEngine

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(std::string choosenText,QObject *parent = nullptr);



signals:
    void updateScoreboard(Result result);
    //This signal will give current position in text to other objects
    void updatePosition(int position);

private:
    std::vector<std::string> gameText;
};

#endif // GAME_H
