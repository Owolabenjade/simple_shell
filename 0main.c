#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
 * main - Entry point for the simple shell.
 * Description: A simple UNIX command interpreter.
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	char *prompt = "$ ";
	pid_t child_pid;

	while (1) {
		printf("%s", prompt);
		nread = getline(&line, &bufsize, stdin); /* Read input */
		if (nread == -1) {
			free(line);
			exit(EXIT_SUCCESS); /* Handle Ctrl+D */
		}

		/* Remove newline at the end of the input */
		line[strcspn(line, "\n")] = 0;

		child_pid = fork();
		if (child_pid == 0) { /* Child process */
			char *argv[] = {line, NULL};
			if (execve(line, argv, NULL) == -1) {
				perror("Error");
				exit(EXIT_FAILURE);
			}
		} else if (child_pid > 0) { /* Parent process */
			wait(NULL); /* Wait for the child process to finish */
		} else {
			perror("fork");
		}
	}

	free(line);
	return (0);
}
