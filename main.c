#include "question_1.h"
#include "question_2.h"
#include "question_3.h"
#include "question_4.h"
#include "question_5.h"
#include "question_6.h"
#include "question_7.h"
#include "question_8.h"


int main() {
    char command[BUFFER_SIZE]; // Buffer to hold user command input

    Welcome_prompt();
    A_better_displayed_prompt();

    while (1) {
        Exit_prompt_or_ctrl_d_prompt(command);

        Execution_time_command(command);  // this function now handles execution and timing so no need to call other execution functions here
    }

}
