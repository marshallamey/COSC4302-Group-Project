#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

// This Command Object repesent a Executable UNIX Program with pre-specfied arguments
//
// Note this command object will spin up a child process, which may 
// fail to execute the program In that case, a ExecutionException will thrown
// Catch in the main function and terminate the program  to avoid having 
// multiple shell processes inquiring user input
// The main process will be unaffected as ExecutionException will only
// be thrown in the child process 

class Command {
    std::vector<std::string> args;
public:
    explicit Command(const std::vector<std::string>& args);
    const std::vector<std::string>& get_args() const;
    void execute(); // throws(ExecutionException)
};

class ExecutionException {
    std::string msg;
public:
    ExecutionException(const std::string& msg);
    const std::string& what() const;
};

#endif // COMMAND_H
