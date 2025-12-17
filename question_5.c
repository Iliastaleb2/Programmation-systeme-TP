#include "question_5.h"

void Execution_time_command(char *command){
    struct timespec start_time, end_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time); // Record start time

    Execution_of_a_simple_command(command); // Execute the command

    clock_gettime(CLOCK_MONOTONIC, &end_time); // Record end time 

    // Calculate elapsed time in milliseconds (with clock get_time we have to add the time in seconds and nanoseconds, then convert it in ms)
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 +
                          (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;

    char prompt_buffer[size_of_new_prompt + 20];  // Buffer to hold the formatted prompt with time
    int lenght = 0;                          // Length of the formatted prompt
    if(WIFEXITED(last_exit_status)){
        lenght = snprintf(prompt_buffer, sizeof(prompt_buffer), Normal_message_with_time, "exit", WEXITSTATUS(last_exit_status), elapsed_time);
    }

    else if(WIFSIGNALED(last_exit_status)){
        lenght = snprintf(prompt_buffer, sizeof(prompt_buffer), Normal_message_with_time, "signal", WTERMSIG(last_exit_status ), elapsed_time);
    }

    else{
        lenght = snprintf(prompt_buffer, sizeof(prompt_buffer), Normal_message_with_time, "unknown", 0, elapsed_time);
    }   
    write(STDOUT_FILENO, prompt_buffer, lenght);
}