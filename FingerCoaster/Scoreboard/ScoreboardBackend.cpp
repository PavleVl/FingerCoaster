#include "ScoreboardBackend.hpp"
#define FPATH "../FingerCoaster/SavedFiles/scoreboard.txt"


std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

void initFile(){
    std::ofstream file(FPATH);  
    file << "Pavle";
    file.close();
}

bool ScoreboardBackend::isFirstTimeCheck(){
    return _isFirstTime;
}

void ScoreboardBackend::loadResults(){

    std::ifstream inFile;
    inFile.open(FPATH);

    //If there is no file for writing we init the file
    if(inFile.fail()){
        _isFirstTime = true;
        initFile();
    }
    

    std::string line;
    //We are gona skip the first line because it contains username
    std::getline(inFile,_username);

    //Adding each result into priority_que
    while(std::getline(inFile,line)){
        std::vector<std::string> components = split(line,'-');
    
        Result curRes(components);
        _results.push_back(curRes);
    }

    
    std::sort(_results.begin(),_results.end());
    inFile.close();
}

void ScoreboardBackend::writeUsername(std::string& username){
    if(_isFirstTime){
        std::ofstream file(FPATH);
        file << username;

        file.close();
        _isFirstTime = false;
    }
}

void ScoreboardBackend::updateScoreboard(Result& result){

    _results.push_back(result);
    
    std::sort(_results.begin(),_results.end());

    if(_results.size() > 10)
        _results.pop_back();

    std::ofstream file(FPATH,std::ios::trunc);

    //TOFIX
    //ILL HARDCODE USERNAME 
    file << "Pavle\n";

    for(unsigned i=0;i<_results.size();i++)
        file << _results[i].formatResultSave();


    file.close();
}

std::vector<Result> ScoreboardBackend::giveResults(){
       return _results;
}

std::string ScoreboardBackend::giveUsername(){
    return _username;
}

std::string ScoreboardBackend::giveFormatedScoreboard(){

    std::stringstream output;

    for(unsigned i=0;i<_results.size();i++)
        output << _results[i].formatResultDisplay();

    return output.str();
}
