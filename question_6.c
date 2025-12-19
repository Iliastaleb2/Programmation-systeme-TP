#include "question_6.h"


void Execution_of_a_command_with_arguments(char *command, char **arguments) {
    
    char *token;
    int index = 0;
    token = strtok(command, " \n"); // tokenizing the command string using space and newline as delimiters
    while (token != NULL && index < MAX_ARGUMENTS - 1) {  
        arguments[index] = token; // storing each argument in the arguments array
        index++; // moving to the next argument
        token = strtok(NULL, " \n"); // getting the next token
    }
    arguments[index] = NULL; // the last argument must be NULL for execvp
    if (fork() == 0) {
        // Child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("Execution failed");
        }
        _exit(EXIT_FAILURE); // exit child process if exec fails
    } else {
        // parent process
        wait(NULL); // waiting for child process to finish
    }    
}