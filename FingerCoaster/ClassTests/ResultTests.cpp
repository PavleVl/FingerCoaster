#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Result.hpp"

#include <ctime>
#include <string>
#include <stdexcept>
#include <iostream>

TEST_CASE("Result class tests"){

    SECTION("Constructor - Wpm out of bounds throws exception"){

            time_t rawTime;
            struct tm* date;
            unsigned wpm = 500;
            int correct = 50;
            int failed = 30;
            std::string username = "username";

            rawTime = time(0);
            date = localtime(&rawTime);
            
            REQUIRE_THROWS(Result(*date,wpm,correct,failed,username));
    }

    SECTION("Format - No empty string"){
        time_t rawTime;
            struct tm* date;
            unsigned wpm = 100;
            int correct = 53;
            int failed = 31;
            std::string username = "username";

            rawTime = time(0);
            date = localtime(&rawTime);
            Result result(*date,wpm,correct,failed,username);
            //std::string formatedOutput = result.formatResult();
            
            //std::cout << formatedOutput << std::endl;
            CHECK(formatedOutput.size() > 0);
    }

}