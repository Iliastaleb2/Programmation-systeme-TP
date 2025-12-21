#include "question_8.h"


void Handling_pipes_between_commands(char *command, char **arguments1, char **arguments2) {
    char *token; 
    int index1 = 0;  // index for first command arguments
    int index2 = 0;  
    int pipe_found = 0;  // number of pipes found

    // for each pipes we separate the commands into two argument arrays
    token = strtok(command, " \n");     
    while (token != NULL && (index1 < MAX_ARGUMENTS - 1 || index2 < MAX_ARGUMENTS - 1)) {  
        if (strncmp(token, "|", 1) == 0) {
            pipe_found = 1; 
            token = strtok(NULL, " \n");  // get the next token
            continue;       // in order to skip adding the pipe token to either arguments array
        }
        if (!pipe_found) {
            arguments1[index1++] = token;  // first command arguments
        } else {
            arguments2[index2++] = token;  
        }
        token = strtok(NULL, " \n");  
    }
    arguments1[index1] = NULL;  // null-terminate the first arguments array
    arguments2[index2] = NULL;  

    int pipefd[2];            // file descriptors for the pipe
    if (pipe(pipefd) == -1) {        
        perror(Pipe_error_message);
        return; 
    }

    pid_t pid1 = fork();       
    if (pid1 == 0) {         
        // First child process
        close(pipefd[0]);         
        dup2(pipefd[1], STDOUT_FILENO);  
        close(pipefd[1]);         

        if (execvp(arguments1[0], arguments1) == -1) {   
            perror(Execution_failed_message);
        }
        _exit(EXIT_FAILURE);        
    } 

    pid_t pid2 = fork(); 
    if (pid2 == 0) {  
        // Second child process
        close(pipefd[1]);         
        dup2(pipefd[0], STDIN_FILENO);  
        close(pipefd[0]);         

        if (execvp(arguments2[0], arguments2) == -1) { 
            perror(Execution_failed_message);
        }
        _exit(EXIT_FAILURE);        
    } 

    // Parent process
    close(pipefd[0]); 
    close(pipefd[1]);          // close both ends of the pipe in parent
    waitpid(pid1, NULL, 0); 
    waitpid(pid2, NULL, 0);   // wait for both child processes to finish
}