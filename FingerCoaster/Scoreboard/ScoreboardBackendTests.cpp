#define CATCH_CONFIG_MAIN

#include "../SavedFiles/catch.hpp"
#include "ScoreboardBackend.hpp"
#include <iostream>

TEST_CASE("Scoreboard class tests"){

    SECTION("File function"){
        
        ScoreboardBackend sc;
        if(!sc.isFirstTimeCheck())
            std::cout << sc.giveFormatedScoreboard() << std::endl;
        else 
            std::cout << "Prvi mi je put";
    }   

}