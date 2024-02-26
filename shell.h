#ifndef SIMPLE_SHELL_H  // If SIMPLE_SHELL_H is not defined
#define SIMPLE_SHELL_H  // Define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_input - Read input from the user.
 *
 * Return: A pointer to the user input.
*/
char *read_input(void);

/**
 * execute_command - Execute the user-input command.
 * @input: User input as a command.
*/
void execute_command(char *input);

#endif /* SIMPLE_SHELL_H */  // End of the include guard
