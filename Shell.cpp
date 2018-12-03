#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Command.hpp"
#include "UnixHelper.hpp"

#define MAX_ARGS 64
#define MAX_ARG_LEN 16
#define MAX_LINE_LEN 128
#define WHITESPACE ".,\t\n"
#define PROMPT_CHARACTER ">"
#define PROMPT_NAME "conch"

//Formats the prompt and outputs to terminal.
void printPrompt()
{
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
    std::string cmdLine;

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
                my_command.execute();
            }
            catch (ExecutionException e)
            {
                std::cout << "An exception occurred: " << e.what() << '\n';
                return 0;
            }
        }
    }
    //We should not reach this.
}
