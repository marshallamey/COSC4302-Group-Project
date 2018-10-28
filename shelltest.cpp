# include <iostream>
# include <cstdio>
# include <unistd.h>
# include <string>
# include <vector>
# include <sstream>

# define LINE_LEN      80
# define MAX_ARGS      64
# define MAX_ARG_LEN   16
# define MAX_PATHS     64
# define MAX_PATH_LEN  96
# define WHITESPACE    " .,\t\n"

#ifndef NULL
# define NULL ...
# endif

using namespace std;

struct command_t {
  string name;
  int argc;
  vector<string> argv;
};

int parsePath(vector<string>&);
int parseCommand(string, struct command_t&);

int main() {
  string commandLine = "Every good boy does fine";
  struct command_t command;
  vector<string> paths;

  //Test functions
  parsePath(paths);
  parseCommand(commandLine, command);

  //Display results
  cout << "\nCommand name: " << command.name << endl;
  cout << "Number of args: " << command.argc << endl;
  
  cout << endl << "ARGUMENTS" << endl;
  for(int i = 0; i < command.argv.size(); i++) 
    cout << command.argv[i] << endl;
  
  cout << endl << "PATHS" << endl;
  for(int i = 0; i < paths.size(); i++) 
    cout << paths[i] << endl;
  cout << endl;
  return 0;
}



int parseCommand(string cLine, struct command_t& cmd) {
/*********************************************************
* This function takes user input from the command line and
* parses the string into a vector of substrings using 
* whitespace as the delimiter.
*********************************************************/

  int argc = 0;
  string token;
  stringstream ss(cLine);
    
  //Split the command line string. Push substrings to vector
  while(getline(ss, token, ' ')) 
  {
    cmd.argv.push_back(token);
    argc++;
  }

  //Set the command name and number of arguments
  cmd.argc = argc;
  cmd.name = cmd.argv[0];

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

