#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char *command)
{
		pid_t pid;
			int status;

				/*Remove the newline character*/
				size_t len = strlen(command);
					if (command[len - 1] == '\n')
							{
										command[len - 1] = '\0';
											}

						pid = fork();

							if (pid == 0)
									{
												/* Child process */
												if (execve(command, NULL, NULL) == -1)
															{
																			perror("Error");
																					}
														exit(EXIT_FAILURE);
															} else if (pid < 0)
																	{
																				/* Fork failed */
																				perror("Error");
																					} else
																							{
																										/* Parent process */
																										waitpid(pid, &status, 0);
																											}
}
