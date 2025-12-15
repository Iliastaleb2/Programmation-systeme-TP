#include "question_2.h"

int last_exit_status = 0; // Global variable to store the last exit status (in particular for question_4.c)

void Execution_of_a_simple_command(char *command){

    // Contrary to the previous version, we do not check for empty commands here because in the main loop,
    // we already read the command and check if it is empty before calling this function.

    int status;
    pid_t pid = fork();                    // creating a new process in order to execute the command

    if (pid == -1){                // managing fork error
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0){               // case of the child process 
        execlp(command, command, NULL);    // executing the command
        perror("Execution failed");
        exit(EXIT_FAILURE);
    }

    // case of a non-existent command
    if (pid > 0 && waitpid(pid, &status, WNOHANG) == -1) {
        write(STDOUT_FILENO, Command_not_found_message, size_of_command_not_found_message);
    }

    else {                       // case of the parent process
        waitpid(pid, &status, 0);    // waiting for the child process to finish
        last_exit_status = status; // storing the exit status for question_4.c
    }
}