#include "../Headers/ScoreboardBackend.hpp"
#define FPATH "../FingerCoaster/SavedFiles/scoreboard.txt"


auto splitStorage (const std::string &s, char delim) -> std::vector<std::string> {
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
    //file << "Pavle";
    file.close();
}

auto ScoreboardBackend::isFirstTimeCheck() -> bool{
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
        std::vector<std::string> components = splitStorage(line,'-');
    
        Result curRes(components);
        _results.push_back(curRes);
    }

    
    std::sort(_results.begin(),_results.end());
    inFile.close();
}

void ScoreboardBackend::writeUsername(std::string& username){
    std::ofstream file(FPATH);
    file << username;

    file.close();
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

    for(auto & _result : _results)
        file << _result.formatResultSave();


    file.close();
}

auto ScoreboardBackend::giveResults() -> std::vector<Result>{
       return _results;
}

auto ScoreboardBackend::giveUsername() -> std::string{
    return _username;
}

auto ScoreboardBackend::giveFormatedScoreboard() -> std::string{

    std::stringstream output;

    for(auto & _result : _results)
        output << _result.formatResultDisplay();

    return output.str();
}
