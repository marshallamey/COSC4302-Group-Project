#include <iostream>
#include <string>
//#include <Parser.hpp>

#define MAX_ARGS 64
#define MAX_ARG_LEN 16
#define MAX_LINE_LEN 80
#define WHITESPACE ".,\t\n"
#define PROMPT_CHARACTER ">"

void printPrompt();
void readCommand(char *);

/*Function prototypes, which exist in ShellTest already??? */
int parseCommand(char *, struct command_t);

void printPrompt()
{
    //TODO:  Build out prompt?
    //String promptString = "";

    std::string prompt = "Conch";
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
    char cmdLine[MAX_LINE_LEN];

    //Initialize Shell

    //Input Loop
    while (1)
    {
        printPrompt();
        //Wait for next input
        std::string command;
        getline(std::cin, command);

        //Act on input

        //Exit command
        if (command == "exit")
        {
            return 0;
        }
        else
        {
            //Parse command.
        }
    }

    //Just exit for now
}

//OBSOLETE

//Normal exit.
//printf("Terminating successfully.  Goodbye.");
//return 0;
