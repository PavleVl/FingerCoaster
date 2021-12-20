#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../Result/Result.hpp"

class Scoreboard{

public:
    inline Scoreboard(){
        _isFirstTime = false;
        loadResults();
    }

    bool isFirstTimeCheck();

    void updateScoreboard(Result& result);

    void writeUsername(std::string& username);

    std::string giveFormatedScoreboard();

private:
    void loadResults();

private:
    std::vector<Result> _results;
    bool _isFirstTime;

};

#endif