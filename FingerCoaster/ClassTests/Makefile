
CXX = g++
CXXFLAGS = -std=c++17 -m64 -Wall -Wextra 

#This section is used for compiling ResultTests
run.out : ResultTests.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
#----------------------------------------------------

#This section is used for compiling ScoreboardTests

#COREBOARDCPP = $(shell find ../ -name "Scoreboard.cpp")
#SCOREBOARDHPP = $(shell find ../ -name "Scoreboard.hpp")

#run.out: scoreboard.o scoreboardTests.o 
#	$(CXX) $(CXXFLAGS) -o $@ $^

#scoreboardTests.o: ScoreboardTests.cpp
#	$(CXX) $(CXXFLAGS) -c -o $@ $<

#scoreboard.o: $(SCOREBOARDCPP) $(SCOREBOARDHPP)
#	$(CXX) $(CXXFLAGS) -c -o $@ $<


.PHONY: clean

clean:
	rm *.out *.o