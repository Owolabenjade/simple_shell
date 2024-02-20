/* shell_functions.c */

#include "shell.h"

char *read_input(void)
{
    char *input = NULL;
    size_t bufsize = 0;

    printf("($) ");
    getline(&input, &bufsize, stdin);

    return input;
}

void execute_command(char *input)
{
    /* Implement command execution logic here */
    printf("Executing: %s", input);
}
