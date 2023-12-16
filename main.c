#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		char *buffer = NULL;
			size_t bufsize = 0;

				while (1)
						{
									printf("$ ");
											/*Use getline from the GNU library, which requires _GNU_SOURCE*/
											ssize_t n = getline(&buffer, &bufsize, stdin);

													if (n == -1)
																{
																				/*Handle end-of-file condition (Ctrl+D)*/
																				printf("\n");
																							break;
																									}

															/*Execute the command using the execute_command function*/
															execute_command(buffer);
																}

					free(buffer);
						return (0);
}
