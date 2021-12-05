#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <ctime>
#include <string>
#include <stdexcept>
#include <iomanip>

class Result{

public:
    Result(std::tm& date,unsigned wpm,int correct,int failed,std::string username){

        if(wpm > 300){ 
            throw std::invalid_argument("Wpm out of range");
        }
        
        _date = date;
        _wpm = wpm;
        _correct = correct;
        _failed = failed;
        _username = username;
    }
    
    unsigned giveWpm() const{
        return _wpm;
    }

    std::string formatResult() {

        std::stringstream formatedResult;

        formatedResult << std::fixed << std::setprecision(2)
                       << _date.tm_mday
                       << ":"
                       <<  _date.tm_mon + 1
                       << ":"
                       << _date.tm_year + 1900
                       << " - "
                       << "Wpm:" << _wpm << " - "
                       << "Accuracy:" << calcAccuracy() << "% - "
                       << "Correct:" << _correct << " - "
                       << "Failed:" << _failed << " - "
                       << "Username:" << _username << std::endl;
                                     
       return formatedResult.str();
    }

private:
    float calcAccuracy(){
        
        int totalWords = _correct + _failed;

        if(totalWords == 0)
            return 0.0;

        return (_correct * 100) / float(totalWords); 
    }

private:
    std::tm _date;
    unsigned _wpm;
    int _correct;
    int _failed;
    std::string _username;

};

#endif
