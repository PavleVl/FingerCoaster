#define CATCH_CONFIG_MAIN

#include "../SavedFiles/catch.hpp"
#include "Storage.hpp"
#include <iostream>
#include <vector>
#include <string>

TEST_CASE("Storage class tests"){

    SECTION("setDifficulty throws exception if out of 0..2 range"){
        
        Storage ourStorage;
        unsigned newDifficulty = 3;

        REQUIRE_THROWS(ourStorage.setDifficulty(newDifficulty));
    }

    SECTION("setNumberOfPlayers throws exception if out of 1..3 range"){
        
        Storage ourStorage;
        unsigned newNumberOfPlayers = 5;

        REQUIRE_THROWS(ourStorage.setNumberOfPlayers(newNumberOfPlayers));
    }

    SECTION("setChoosenFile throws exception if file name is missing"){
        
        Storage ourStorage;
        std::string newFname = "";

        REQUIRE_THROWS(ourStorage.setChoosenFIle(newFname));
    }



    SECTION("formatTextForGame throws exception if text is missing"){

        Storage ourStorage;
        
        REQUIRE_THROWS(ourStorage.formatTextForGame());
    }

    //TODO
    //Write test for loading a fail
    
    //TODO
    //Write test for formatGameOutput

}        
