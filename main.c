#include "question_1.h"
#include "question_2.h"

int main() {
    Welcome_prompt();
    Normal_prompt();

    while (1) {
        char command[MAX_COMMAND_LENGTH];
        Execution_of_a_simple_command(command);
        Normal_prompt();
    }

}