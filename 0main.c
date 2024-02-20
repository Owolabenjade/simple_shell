/* main.c */

#include "shell.h"

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
