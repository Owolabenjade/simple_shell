/* shell_functions.c */

#include "shell.h"

/**
*read_input - Read input from the user
*
*Return: A pointer to the user input
*/

char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	printf("($) ");
	getline(&input, &bufsize, stdin);

	return (input);
}

/**
*execute_command - Execute the user-input command
*@input: User input as a command
 */
 
void execute_command(char *input)
{
	/* Implement command execution logic here */
	printf("Executing: %s", input);
}
