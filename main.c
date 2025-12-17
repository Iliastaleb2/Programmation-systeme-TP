#include "question_1.h"
#include "question_2.h"
#include "question_3.h"
#include "question_4.h"
#include "question_5.h"
#include "question_6.h"

#define Size_of_command 256

int main() {
    char command[Size_of_command];
    
    Welcome_prompt();
    A_better_displayed_prompt();

    while (1) {
        Exit_prompt_or_ctrl_d_prompt(command);

        if (command[0] != '\0') {
            Execution_time_command(command);
        }
    }
}