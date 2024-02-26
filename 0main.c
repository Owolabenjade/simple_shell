#include "shell.h"

/**
 * main - Entry point for the simple shell.
 * Return: Always returns 0 (Success).
 */
int main(void);{
	char *buffer = NULL;
	size_t bufsize = 1024;
	ssize_t characters;
	pid_t child_pid;
	int status;
	char *argv[2]; /* Array for command and NULL */

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	while (1)
	{
		printf("$ "); /* Display prompt */
		characters = getline(&buffer, &bufsize, stdin); /* Read command */
		if (characters == -1)
		{
			if (feof(stdin)) /* End of file condition (Ctrl+D) */
			{
				printf("\n");
				free(buffer);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("getline");
				continue;
			}
		}

		buffer[characters - 1] = '\0'; /* Remove newline character */
		argv[0] = buffer; /* Command to execute */
		argv[1] = NULL; /* No arguments */

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			continue;
		}
		if (child_pid == 0)
		{
			/* Child process */
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(argv[0]); /* Print error if execve fails */
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			wait(&status); /* Wait for child process to complete */
		}
	}

	free(buffer); /* Free allocated buffer */
	return (0);
}
