# include <stdio.h>
# include <unistd.h>
//# include <shell.hpp>
# include <Parser.hpp>

#define MAX_ARGS 64
#define MAX_ARG_LEN 16
#define MAX_LINE_LEN 80
#define WHITESPACE ".,\t\n"
#define PROMPT_CHARACTER ">"

void printPrompt();
void readCommand(char *);

//OBSOLETE
stuct command_t{
    chr *name;
    int argc;
    char *argv[MAX_ARGS];
}

/*Function prototypes, which exist in ShellTest already??? */
int parseCommand(char *, struct command_t);

void printPrompt(){
    //TODO:  Build out prompt?
    //String promptString = "";
    printf("s",PROMPT_CHARACTER);
}

void readCommand(char *buffer){
    //TODO:  Upgrade this.
    gets(buffer);
}

int main(int argc, char *argv[]){
    int i;
    int pid;
    int status;
    FILE *fid;
    char cmdLine[MAX_LINE_LEN];

    //Startup
    printPrompt();
    //Input Loop
    while (1){
        //Wait for next input
        
        //Act on input
        
        //Just exit for now
        exit;
    }

    //OBSOLETE

    //Normal exit.
    printf("Terminating successfully.  Goodbye.");
    return 0;
}