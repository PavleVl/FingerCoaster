#define CATCH_CONFIG_MAIN

#include "../SavedFiles/catch.hpp"
#include "Result.hpp"

#include <ctime>
#include <string>
#include <stdexcept>
#include <iostream>

TEST_CASE("Result class tests"){

    SECTION("Constructor - Wpm out of bounds throws exception"){

            std::string date = "12:3:2021";
            unsigned wpm = 500;
            int correct = 50;
            int failed = 30;
            std::string username = "username";

            
            REQUIRE_THROWS(Result(date,wpm,correct,failed,username));
    }

    SECTION("Format - No empty string"){
            
            std::string date = "12:3:2021";
            unsigned wpm = 100;
            int correct = 53;
            int failed = 31;
            std::string username = "username";

            Result result(date,wpm,correct,failed,username);
            std::string formatedOutput = result.formatResultSave();
            
            std::cout << formatedOutput << std::endl;
            CHECK(formatedOutput.size() > 0);
    }

}