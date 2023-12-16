#include "shell.h"

void execute_command(char *line)
{
		pid_t pid;
			int status;

				line[strlen(line) - 1] = '\0'; // Remove the newline character

					pid = fork();

						if (pid == -1)
								{
											perror("fork");
													exit(EXIT_FAILURE);
														}

							if (pid == 0)
									{
												if (execve(line, NULL, NULL) == -1)
															{
																			perror(line);
																						exit(EXIT_FAILURE);
																								}
													}
								else
										{
													waitpid(pid, &status, 0);

															if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
																			return;
																	else
																					fprintf(stderr, "./hsh: 1: %s: not found\n", line);
																		}
}
