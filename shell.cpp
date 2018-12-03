#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Command.hpp"

#define MAX_ARGS 64
#define MAX_ARG_LEN 16
#define MAX_LINE_LEN 80
#define WHITESPACE ".,\t\n"
#define PROMPT_CHARACTER ">"

void printPrompt();
void readCommand(char *);

void printPrompt()
{
    //TODO:  Build out prompt?
    //String promptString = "";

    std::string prompt = "conch";
    prompt.append(PROMPT_CHARACTER);
    //printf(prompt);
    std::cout << prompt;
}

void readCommand(char *buffer)
{
    //TODO:  Upgrade this.
    //gets(buffer);
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

        //Exit command
        if (cmdLine == "exit")
        {
            return 0;
        }
        else
        {
            //Parse command.

            //Execute command
            try
            {
                //Create command object.
                Command my_command = make_command(cmdLine);
                //Try execute
                my_command.execute();
            }
            catch (ExecutionException e)
            {
                std::cout << "An exception occurred. " << e.what() << '\n';
            }
        }
    }

    //Just exit for now
}

//OBSOLETE

//Normal exit.
//printf("Terminating successfully.  Goodbye.");
//return 0;
