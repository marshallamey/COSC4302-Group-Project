# include <iostream>
# include <cstdio>
# include <unistd.h>
# include <string>
# include <vector>
# include <sstream>
# include "Main.h"

using namespace std;

// **Tip: Avoid the use out-parameters use return values when possible,
//        As the caller may not know what pass to you
// **Tip: If you need to convey the occasional error, use exceptions insted of error codes
// **Tip: Strings and vectors are consider to be large objects, pass by const reference
//        to avoid copying to the function
// **Ideal:    Command parseCommand(const string& cLine);
// **NotIdeal: int parseCommand(string cLine, Command& cmd);
int parsePath(vector<string>&);
int parseCommand(string, Command&);

// **Issue: We need a path resolver function as the Command object is unable to determine where
//        a progam file is. Refer to Parser.hpp for the rules of program path resolution and 
//        UnixHelper.hpp for some helper functions to aid in your implementation.

// **Bug: C++ programs may only have one main function, one can not include a file
//        with a main function as a result of this rule. Meaning Alex can not refer
//        to this file. Factor out the main method into Test.cpp file, but leave the parsing
//        functions here.
int main() {
  // **Style: In C++, It is encourage to only define a varaible when you need it. 
  //      Avoid predefining your variables at the start of the function if possible.
  vector<string> paths; 
  Command cmd;  
  string commandLine = "Every good boy does fine";

  //Test functions
  parsePath(paths);
  parseCommand(commandLine, cmd);

  // **MinorIssue: favour '\n' over endl for the sake of performance
  // **MyBad: Not including a way to read my data member was a poor choice on my part
  //       I now have altered my Command Header File to include a Command.get_args() function
  
  //Display results
  cout << "\nCommand name: " << cmd.filename << endl;
  cout << "Number of args: " << cmd.args.size() << endl;
  
  cout << endl << "ARGUMENTS" << endl;
  for(int i = 0; i < cmd.args.size(); i++) 
    cout << cmd.args[i] << endl;
  
  cout << endl << "PATHS" << endl;
  for(int i = 0; i < paths.size(); i++) 
    cout << paths[i] << endl;
  cout << endl;
  return 0;
}

int parseCommand(string cLine, Command& cmd) {
  /*********************************************************
   * This function takes user input from the command line and
   * parses the string into a vector of substrings using 
   * whitespace as the delimiter.
   *********************************************************/

  string token;
  stringstream ss(cLine);
    
  // **Tip: Only mutate the internal state of an object with said objects's member functions
  //        that way said object does need to worry about external force invaliding it. 
  // **Request: Consider using a constructing a std::vector of your own to populate, then
  //        pass this vector in the constructor 
  // **Bug: you may be filling args with empty of whitespace arguments, Review ParserTest.cpp 
  //        for the desired input/outputs

  //Split the command line string. Push substrings to vector
  while(getline(ss, token, ' ')) cmd.args.push_back(token);

  // **MyBad: I have change the Header file for Command objects, There is no need to handle the 
  //        filename field any more. If will be assumed from the first item of the argument list
  // **Issue: Remember that Command objects have no means of Path Resolution, it is on you
  //        to determined the absolute location of the progam file an reassign the first item 
  //        item of the argument list to said absolute Location.
  //Set the command name
  cmd.filename = cmd.args[0];

  // **Tip: If a function has no way of producing an error, do not return an error code
  // **Request: Consider invoking the Command constructor and returning a Command object instead. 
  return 1;
}

int parsePath(vector<string>& dirs) {
  /************************************************************ 
   * This function reads the PATH variable for this environment,
   * then builds a vector, dirs, of the directories in PATH
   ************************************************************/
  
  // **MinorBug: In C++, C-style casting is consider not-safe do its the unprediable nature 
  // **Request: Consider using the std::string constructor e.g. string(getenv("PATH"))
  string pathEnvVar = (string)getenv("PATH");
  stringstream ss(pathEnvVar);
  string token;

  // **Request: Consider using a constructing a std::vector of your own to populate, and returning
  //        that instead of error code
  // **Bug: you may be filling the vector with empty of colon-only directorys, Review ParserTest.cpp 
  //        for the desired input/outputs
  
  //Loop to parse the path.
  //Look for a ':' delimiter between each path name.
  while(getline(ss, token, ':')) { dirs.push_back(token); }

  // **Tip: If a function has no way of producing an error, do not return an error code
  // **Request: Consider returning a std::vector object instead. 
  return 1;
}
