COMPILER=g++
FLAGS=-std=c++11 -Wall -Wextra -Wpedantic

all: Shell

Shell : Shell.cpp Parser.cpp UnixHelper.cpp Command.cpp
	$(COMPILER) $(FLAGS) -o shell Shell.cpp Parser.cpp UnixHelper.cpp Command.cpp &&  echo "\n CREATED ./shell PROGRAM "
	
ParserTest : ParserTest.cpp Parser.o Command.o UnixHelper.o
	$(COMPILER) $(FLAGS) -o parser-test ParserTest.cpp Parser.o Command.o UnixHelper.o && ./parser-test

UnixHelperTest : UnixHelperTest.cpp UnixHelper.o
	$(COMPILER) $(FLAGS) -o unix-helper-test UnixHelperTest.cpp UnixHelper.o && ./unix-helper-test

CommandTest : CommandTest.cpp Command.o
	$(COMPILER) $(FLAGS) -o command-test CommandTest.cpp Command.o && ./command-test

Parser.o : Parser.hpp Parser.cpp 
	$(COMPILER) $(FLAGS) -c Parser.hpp Parser.cpp

UnixHelper.o : UnixHelper.hpp UnixHelper.cpp 
	$(COMPILER) $(FLAGS) -c UnixHelper.hpp UnixHelper.cpp 

Command.o : Command.hpp Command.cpp 
	$(COMPILER) $(FLAGS) -c Command.hpp Command.cpp 
	
.PHONY : clean
	
clean : 
	rm -f shell parser-test unix-helper-test command-test core *.o *.gch
	

