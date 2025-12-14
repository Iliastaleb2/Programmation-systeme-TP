#include "question_2.h"

void Execution_of_a_simple_command(char *command){

    ssize_t bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH - 1);   // Stocking the number of bytes read from the input

    int status;
    pid_t pid = fork();                    // creating a new process in order to execute the command

    if (bytes_read > 0) {   // if there is something read
        
        if (command[bytes_read - 1] == '\n') {  // we supress the \n at the end of the command 
            command[bytes_read - 1] = '\0';     // because if we dont, execlp will not work properly (wont find the command)
        }
    } 
    else {
            command[bytes_read] = '\0';         // if nothing is read, we just put \0 at the beginning of the command to avoid garbage values
    }

    if (pid == -1){                // managing fork error
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0){               // case of the child process 
        execlp(command, command, NULL);    // executing the command
        perror("Execution failed");
        exit(EXIT_FAILURE);
    }

    else {                       // case of the parent process
        waitpid(pid, &status, 0);    // waiting for the child process to finish
    }
}