#include "question_1.h"

int main() {
    Welcome_prompt();
    Normal_prompt();
while(1){
    char command_entered_by_user[128];  
    Execution_of_a_simple_command(command_entered_by_user);
    Normal_prompt();
    if (feof(stdin)) {
        Exit_prompt_or_ctrl_d_prompt();
}


    return EXIT_SUCCESS;

}
}

