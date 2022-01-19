#ifndef SCOREBOARDBACKEND_HPP
#define SCOREBOARDBACKEND_HPP

#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Result.hpp"

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

    std::string giveUsername();

    std::vector<Result> giveResults();

private:
    void loadResults();

private:
    std::string _username;
    std::vector<Result> _results;
    bool _isFirstTime;

};

#endif
