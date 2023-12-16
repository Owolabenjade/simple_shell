#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/* Function prototypes */
void display_prompt(void);
char *read_line(void);
void execute_command(char *command);

#endif /* MAIN_H */
