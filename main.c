#include "main.h"

int main(void)
{
	char *command;

			while (1)
					{
								display_prompt();
										command = read_line();
											   /* Remove the newline character */
											   command[strlen(command) - 1] = '\0';  

											   		execute_command(command);

															free(command);
																}

				return (0);
}
