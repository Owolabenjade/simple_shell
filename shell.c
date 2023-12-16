#include "shell.h"

void display_prompt(void)
{
	printf("#cisfun$ ");
}

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(line);
																						exit(EXIT_SUCCESS);
																								} else {
																												perror("getline");
																															exit(EXIT_FAILURE);
																																	}
										}

					return (line);
}

void execute_command(char *command)
{
		pid_t child_pid;
			int status;

				child_pid = fork();
					if (child_pid == -1)
							{
										perror("fork");
												exit(EXIT_FAILURE);
													}

						if (child_pid == 0)
								{
											/* Child process */
											if (execve(command, NULL, NULL) == -1)
														{
																		perror("execve");
																					exit(EXIT_FAILURE);
																							}
												} else {
															/* Parent process */
															waitpid(child_pid, &status, 0);
																}
}

int main(void)
{
		char *command;

			while (1) {
						display_prompt();
								command = read_line();
										command[strlen(command) - 1] = '\0';

												execute_command(command);

														free(command);
															}

				return (0);
}