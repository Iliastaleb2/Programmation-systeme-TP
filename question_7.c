#include "question_7.h"


void Managing_redirections_to_stdin_and_stdout_with_arrows(char *command, char **arguments) {
    char *token; 
    int index = 0; 
    token = strtok(command, " \n"); // same technique as qst 6 to tokenize the command string
    while (token != NULL && index < MAX_ARGUMENTS - 1) {  
        arguments[index] = token; 
        index++; 
        token = strtok(NULL, " \n"); 
    }
    arguments[index] = NULL; 
    if (fork() == 0) {  
        // Child process
        for (int i = 0; arguments[i] != NULL; i++) {
            if (strcmp(arguments[i], ">") == 0) { // we allow ourselves to use strcmp here to compare strings
                // Redirect stdout to file
                int fd = open(arguments[i + 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); // create or open file for writing with appropriate permissions (rw-r--r--)
                if (fd < 0) { // if file cannot be opened or created
                    perror("Open failed");
                    _exit(EXIT_FAILURE); //exit CHILD process with failure
                }
                dup2(fd, STDOUT_FILENO); // duplicate file descriptor to stdout in order to redirect output
                close(fd); // close original file descriptor
                arguments[i] = NULL; // terminate arguments before redirection symbol
                break; // exit loop after handling redirection
            } 
            else if (strcmp(arguments[i], "<") == 0) {
                // Redirect stdin from file
                int fd = open(arguments[i + 1], O_RDONLY); // open file for reading only because it's input redirection
                if (fd < 0) { 
                    perror("Open failed");
                    _exit(EXIT_FAILURE);
                }
                dup2(fd, STDIN_FILENO); // duplicate file descriptor to stdin to redirect input this time
                close(fd);
                arguments[i] = NULL;
                break;
            }
        }
        if (execvp(arguments[0], arguments) == -1) { 
            perror("Execution failed");
        }
        _exit(EXIT_FAILURE); // exit child process if exec fails
    } 
    else {
        // parent process
        wait(NULL); 
    }
    
}