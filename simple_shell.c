#include "shell.h"

int main(void)
{
		char *line;
			size_t len = 0;

				while (1)
						{
									printf("$ ");
											getline(&line, &len, stdin);

													if (line == NULL)
																{
																				printf("\n");
																							free(line);
																										exit(EXIT_SUCCESS);
																												}

															execute_command(line);

																	free(line);
																		}

					return (0);
}
