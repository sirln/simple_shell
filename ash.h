#ifndef ASH_SHELL
#define ASH_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;

int main(int argc, char **argv);

void ash(char **command);
void prompt(void);
char *get_command(void);
void parse_command(char *command, char **args);
int run_command(char **command);
int _putchar(char c);
#endif
