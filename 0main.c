/* main.c */

#include "shell.h"

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
*/

int main(void)
{
	char *input;

	while (1)
	{
		input = read_input();
		if (input == NULL)
			break;

		execute_command(input);

		free(input);
	}

	return (0);
}
