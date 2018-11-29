#include <vector>
#include <string>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include "Command.hpp"

// Converts a vector of strings to a vector of mutable char *
std::vector<char*> to_argv(const std::vector<std::string>& args) {
    std::vector<char*> argv { };
    for (auto& arg : args) {
        argv.push_back(const_cast<char *>(arg.c_str()));
    }
    argv.push_back(nullptr);
    return argv;
}

// Contruct a command from a an arguement vector
// As per POSIX standards, the first arguement is the 
// path to program it self.
Command::Command(const std::vector<std::string>& args)
    : args(args) { }

// Forks a process and executes a command or 
//   throw an exception on the CHILD PROCESS to ensure
//   the command args are properly destructed
void Command::execute() {
    if (!args.empty()) {
        if (fork() == 0) {
            auto argv = to_argv(args);
            execv(argv.front(), argv.data());
            throw ExecutionException { args[0] + ": " + strerror(errno) };  
        } else {
            wait(nullptr);
        }
    }
}

// Arguments accessor
const std::vector<std::string>& Command::get_args() const {
  return args;
}

// A Simple Exception with a message explaining what went wrong
ExecutionException::ExecutionException(const std::string& msg)
    : msg(msg) { }

// Yield the Exception's Error Message 
const std::string& ExecutionException::what() const {
    return msg;
}


