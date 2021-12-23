#include "Storage.hpp"

//TOFIX 
//This path refers from build directory
#define PATH "../FingerCoaster/SavedFiles/Texts/"

std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

//Geters
unsigned Storage::getDifficulty() const{
    return difficulty;
}

unsigned Storage::getNumberOfPlayers() const{
    return numberOfPlayers;
}

std::string Storage::getChoosenFile() const{
    return choosenFile;
}
//-----------------------------------------------------------------------------------------------------

//Seters
void Storage::setDifficulty(unsigned newDifficulty){
    
    if(newDifficulty > 2)
        throw std::invalid_argument("Difficulty is out of range");


    difficulty = newDifficulty;
}

void Storage::setNumberOfPlayers(unsigned newNumberOfPlayers){

    if(newNumberOfPlayers == 0 || newNumberOfPlayers > 3)
        throw std::invalid_argument("NumberOfPlayers is out of range");

    numberOfPlayers = newNumberOfPlayers;
}

void Storage::setChoosenFIle(std::string newChoosenFile){

    if(newChoosenFile == "")
        throw std::invalid_argument("File name is missing");

    choosenFile = newChoosenFile;
}

//-----------------------------------------------------------------------------------------------------

void Storage::pickRandomFile(){

    std::string fName = "";
    switch(difficulty){
        case 0:
            fName = "easy";
            break;
        case 1:
            fName = "medium";
            break;
        case 2:
            fName = "hard";
            break;
    }

    srand(time(NULL));
    fName += std::to_string(rand() % 3 + 1);
    fName += ".txt";

    choosenFile = fName;
}

//If we are client we want to set randomTextFlag to false
// and do setChosenPath first and then call this function.
//--------------------------------------------------------
//If we are server we are calling this function as with true
//flag so that we choose random file
void Storage::loadText(bool randomTextFlag){

    if(randomTextFlag)
        pickRandomFile();

    if(choosenFile.size() == 0){
        //TODO SIGNAL FOR ERROR
    }

    std::string fullPath = PATH + choosenFile;

    std::ifstream inFile;
    inFile.open(fullPath);

    if(inFile.fail())
        throw std::ios::failure("File missing or corrupt" + fullPath);

    text = "";
    std::string curLine = "";
    while(getline(inFile,curLine))
        text += curLine;


    inFile.close();
}

std::vector<std::string> Storage::formatTextForGame() const{

    if(text.size() == 0)
        throw std::invalid_argument("Missing text");


    return split(text,' ');
}
