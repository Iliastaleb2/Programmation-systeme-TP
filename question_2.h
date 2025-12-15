#include "question_1.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 128

#define Command_not_found_message "Command not found\n"
#define size_of_command_not_found_message 18

extern int last_exit_status; // Declaration of the external variable to store the last exit status

void Execution_of_a_simple_command(char *command);