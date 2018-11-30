#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

/* This Command Object repesent a Executable UNIX Program with pre-specfied arguments
 *
 * Note this command object will spin up a child process, which may 
 * fail to execute the program In that case, a ExecutionException will thrown
 * Catch in the main function and terminate the program  to avoid having 
 * multiple shell processes inquiring user input
 * The main process will be unaffected as ExecutionException will only
 * be thrown in the child process 
 *
 * Also note that this object has no mutator methods. Meaning once the 
 * filename and arguments are set, they can not be altered. This was done 
 * prevent the Command object from ever being in a invalid state.
 */
 
class Command {
    std::string filename;
    std::vector<std::string> args;
public:
    Command(const std::string& filename ,const std::vector<std::string>& args);
    Command();
    
    const std::string& get_filename() const;
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
