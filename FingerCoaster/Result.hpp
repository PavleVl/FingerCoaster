#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <stdexcept>
#include <iomanip>


class Result{

public:
    Result(std::string date,unsigned wpm,int correct,int failed,std::string username){

        if(wpm > 300){ 
            throw std::invalid_argument("Wpm out of range!");
        }
        
        _date = date;
        _wpm = wpm;
        _correct = correct;
        _failed = failed;
        _username = username;
    }
    
    Result(std::vector<std::string>& formatedResult){

        if(formatedResult.size() == 0){
            throw std::invalid_argument("Result class arguments missing!");
        }


        _date = formatedResult[0];
        _wpm = std::stoul(formatedResult[1]);
        _correct = std::stoi(formatedResult[3]);
        _failed = std::stoi(formatedResult[4]);
        _username = formatedResult[5];
    }

    unsigned giveWpm() const{
        return _wpm;
    }

    std::string formatResultDisplay() {

        std::stringstream formatedResult;

        formatedResult << std::fixed << std::setprecision(2)
                       << _date << " - "
                       << "Wpm:" << _wpm << " - "
                       << "Accuracy:" << calcAccuracy() << "% - "
                       << "Correct:" << _correct << " - "
                       << "Failed:" << _failed << " - "
                       << "Username:" << _username << std::endl;
                                     
       return formatedResult.str();
    }

    std::string formatResultSave(){

        std::stringstream formatedResult;

        formatedResult << std::fixed << std::setprecision(2)
                       << _date
                       << "-"
                       << _wpm << "-"
                       << calcAccuracy() << "-"
                       << _correct << "-"
                       << _failed << "-"
                       << _username << std::endl;

        return formatedResult.str();
    }

    float calcAccuracy(){
        
        int totalWords = _correct + _failed;

        if(totalWords == 0)
            return 0.0;

        return (_correct * 100) / float(totalWords); 
    }

private:
    std::string _date;
    unsigned _wpm;
    int _correct;
    int _failed;
    std::string _username;

};

#endif
