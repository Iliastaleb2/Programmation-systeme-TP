#include "question_1.h"


void Welcome_prompt(){
    write(STDOUT_FILENO, "Welcome to the shell !\n", size_of_welcome_prompt);
}

void Normal_prompt(){
    write(STDOUT_FILENO, "enseaSH$\n", size_of_normal_prompt);
}