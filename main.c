nclude "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		char *buffer = NULL;
			size_t bufsize = 0;

				while (1)
						{
									printf("$ ");
											getline(&buffer, &bufsize, stdin);

													/*Execute the command using the execute_command function*/
													execute_command(buffer);
														}

					free(buffer);
						return (0);
}
