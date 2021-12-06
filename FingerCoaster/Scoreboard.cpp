#include "Scoreboard.hpp"
#define FPATH "SavedFiles/scoreboard.txt"


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
    file.close();
}

bool Scoreboard::isFirstTimeCheck(){
    return _isFirstTime;
}

void Scoreboard::loadResults(){

    std::ifstream inFile;
    inFile.open(FPATH);

    //If there is no file for writing we init the file
    if(inFile.fail()){
        Scoreboard::_isFirstTime = true;
        initFile();
    }
    

    std::string line;
    //We are gona skip the first line because it contains username
    std::getline(inFile,line);

    //Adding each result into priority_que
    while(std::getline(inFile,line)){
        std::vector<std::string> components = split(line,'-');
    
        Result curRes(components);
        Scoreboard::_results.push_back(curRes);
    }

    
    std::sort(_results.begin(),_results.end());
    inFile.close();
}

void Scoreboard::writeUsername(std::string& username){
    if(_isFirstTime){
        std::ofstream file(FPATH)
        file << username;

        file.close();
        _isFirstTime = false;
    }
}

void Scoreboard::updateScoreboard(Result& result){

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

std::string Scoreboard::giveFormatedScoreboard(){

    std::stringstream output;

    for(unsigned i=0;i<_results.size();i++)
        output << _results[i].formatResultDisplay();

    return output.str();
}

int main(){

    Scoreboard sc;

    std::vector<std::string> arr = split("12:3:2021-250-63.10-53-31-username",'-');
    Result res(arr);
    sc.updateScoreboard(res);
    
    std::string str = "NePavle";
    sc.writeUsername(str);

    std::cout << sc.giveFormatedScoreboard();
    return 0;
}