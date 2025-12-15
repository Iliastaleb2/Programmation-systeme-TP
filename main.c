#include "question_1.h"
#include "question_2.h"
#include "question_3.h"
#include "question_4.h"

int main() {
    char command[MAX_COMMAND_LENGTH];

    Welcome_prompt();

    while (1) {
        A_better_displayed_prompt();
        Exit_prompt_or_ctrl_d_prompt(command);
        if (command[0] != '\0') { // if the command is not empty
            Execution_of_a_simple_command(command);
        }
    }
}