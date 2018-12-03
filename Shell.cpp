
// Author: Alexander Macey
// Instructor: Bo Sun
// COSC 4302: Operating Systems
// Shell Component - Source

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

//Trim whitespace
std::string trim(const std::string &document)
{

    auto pos = document.find_first_not_of(" \n\t\r");

    auto end_pos = document.find_last_not_of(" \n\t\r");

    if (pos == std::string::npos)
    {

        return "";
    }

    else if (end_pos == std::string::npos)
    {

        return document.substr(pos);
    }

    else
    {

        return document.substr(pos, end_pos - pos + 1);
    }
}

int main()
{
    std::string cmdLine;

    //Initialize Shell

    //Input Loop
    while (std::cin)
    {

        printPrompt();
        //Wait for next input
        getline(std::cin, cmdLine);
        cmdLine = trim(cmdLine);
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
    //Only reach this if you killed CIN
    std::cout << "Goodbye.\n";

}
