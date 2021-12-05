#ifndef STUDENT_HPP
#define STUDENT_HPP

#include<ctime>
#include<string>

class Result{

public:
    Result(std::tm& date,unsigned wpm,float accuracy,std::string username){

        
        

    }


private:
    std::tm _date;
    unsigned _wpm;
    float  _accuracy;
    std::string _username;
    
};

#endif


//Atributi
//date - date
//wpm - short
//percentage - float
//correct - short 
//failed - short 
//user - User
//--------
//getwpm - Short 
//getruslt - String

