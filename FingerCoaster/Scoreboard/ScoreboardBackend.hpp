#ifndef SCOREBOARDBACKEND_HPP
#define SCOREBOARDBACKEND_HPP

#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../Result/Result.hpp"

class ScoreboardBackend{

public:
    inline ScoreboardBackend(){
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