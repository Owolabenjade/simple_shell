#include "shell.h"
#include <string.h>
#include <sys/wait.h>

/**
 * read_input - Read input from the user.
 *
 * Return: A pointer to the user input.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			return (NULL);
		}
		else
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
	}

	return (input);
}

/**
 * execute_command - Execute the user-input command.
 * @input: User input as a command.
 */
void execute_command(char *input)
{
	pid_t pid;
	int status;

	/* Remove newline character from input */
	input[strcspn(input, "\n")] = '\0';

	pid = fork();

	if (pid == -1)
	{
		perror("Error creating child process");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* Child process */
		char *args[] = {input, NULL};
		if (execve(input, args, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
		{
			/* Executable not found */
			fprintf(stderr, "Command not found: %s\n", input);
		}
	}
}
