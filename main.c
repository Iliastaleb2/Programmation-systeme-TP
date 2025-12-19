#include "question_1.h"
#include "question_2.h"
#include "question_3.h"
#include "question_4.h"
#include "question_5.h"
#include "question_6.h"


int main() {
    char command[MAX_COMMAND_LENGTH];
    char *arguments[MAX_ARGUMENTS];
    Welcome_prompt();

    while (1) {
        A_better_displayed_prompt();
        Exit_prompt_or_ctrl_d_prompt(command);

        if (command[0] != '\0' && arguments[0] == NULL) {
            Execution_of_a_simple_command(command);
        }
        else if (arguments[0] != NULL) {
            Execution_of_a_command_with_arguments(command, arguments);
        }
    }
}