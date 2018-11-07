# include <iostream>
# include <cstdio>
# include <unistd.h>
# include <string>
# include <vector>
# include <sstream>
# include "Main.h"

using namespace std;

int parsePath(vector<string>&);
int parseCommand(string, Command&);

int main() {
  vector<string> paths; 
  Command cmd;  
  string commandLine = "Every good boy does fine";

  //Test functions
  parsePath(paths);
  parseCommand(commandLine, cmd);

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
    
  //Split the command line string. Push substrings to vector
  while(getline(ss, token, ' ')) cmd.args.push_back(token);

  //Set the command name
  cmd.filename = cmd.args[0];

  return 1;
}


int parsePath(vector<string>& dirs) {
  /************************************************************ 
   * This function reads the PATH variable for this environment,
   * then builds a vector, dirs, of the directories in PATH
   ************************************************************/

  string pathEnvVar = (string)getenv("PATH");
  stringstream ss(pathEnvVar);
  string token;

  //Loop to parse the path.
  //Look for a ':' delimiter between each path name.
  while(getline(ss, token, ':')) { dirs.push_back(token); }

  return 1;
}
