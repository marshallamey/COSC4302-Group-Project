COMPILER=g++
FLAGS=-std=c++11 -Wall -Wextra -Wpedantic

all: Shell

Shell : Shell.cpp Parser.o UnixHelper.o Command.o
	$(COMPILER) $(FLAGS) -o shell Shell.cpp Parser.o UnixHelper.o Command.o
	
ParserTest : ParserTest.cpp Parser.o UnixHelper.o Command.o
	$(COMPILER) $(FLAGS) -o parser-test ParserTest.cpp Parser.o UnixHelper.o Command.o

UnixHelperTest : UnixHelperTest.cpp UnixHelper.o
	$(COMPILER) $(FLAGS) -o unix-helper-test UnixHelperTest.cpp UnixHelper.o

CommandTest : CommandTest.cpp Command.o
	$(COMPILER) $(FLAGS) -o command-test CommandTest.cpp Command.o

Parser.o : Parser.hpp Parser.cpp 
	$(COMPILER) $(FLAGS) -c Parser.hpp Parser.cpp 

UnixHelper.o : UnixHelper.hpp UnixHelper.cpp 
	$(COMPILER) $(FLAGS) -c UnixHelper.hpp UnixHelper.cpp 

Command.o : Command.hpp Command.cpp 
	$(COMPILER) $(FLAGS) -c Command.hpp Command.cpp 
	
.PHONY : clean
	
clean : 
	rm -f shell parser-test unix-helper-test command-test core *.o *.gch
	

