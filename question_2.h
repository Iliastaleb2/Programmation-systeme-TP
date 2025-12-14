#include "question_1.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 128

void Execution_of_a_simple_command(char *command);