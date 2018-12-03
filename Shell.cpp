#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Command.hpp"
#include "UnixHelper.hpp"
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_ARGS 64
#define MAX_ARG_LEN 16
#define MAX_LINE_LEN 128
#define WHITESPACE ".,\t\n"
#define PROMPT_CHARACTER ">"
#define PROMPT_NAME "conch"

void printPrompt()
{
    //TODO:  Build out prompt?
    //String promptString = "";
    std::string prompt;
    prompt.append(getenv("USER"));
    prompt.append("@");
    prompt.append(PROMPT_NAME);
    prompt.append(PROMPT_CHARACTER);

    //printf(prompt);
    std::cout << prompt;
}

int main()
{
    int i;
    int pid;
    int status;
    FILE *fid;
    std::string cmdLine;

    //Initialize Shell

    //Input Loop
    while (1)
    {

        printPrompt();
        //Wait for next input
        getline(std::cin, cmdLine);

        //Act on input
        //Check for exit command
        if (cmdLine == "exit")
        {
            std::cout << "Goodbye.\n";
            return 0;
        }
        else
        {
            //Parse command.
            Command my_command = make_command(cmdLine);
            //Execute command
            try
            {
                //Try execute
                my_command.execute();
            }
            catch (ExecutionException e)
            {
                std::cout << "An exception occurred: " << e.what() << '\n';
                return 0; //Quit this process.  Seems a bit dangerous.  Need to lookk at improving this.
            }
        }
    }

    //We should not reach this.
    std::cout << "These aren't the Strings you're looking for.";
}
