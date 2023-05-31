#ifndef ASH_SHELL
#define ASH_SHELL

#define BUFSIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
  * struct memory - structure name
  * @size: First member
  * @data: Second member
  *
  *Description: memory block structure
  *
  */

typedef struct memory
{
	size_t size;
	char *data;
} memory_block;

/**
 * struct builtin_f - defines shell builtin commands
 * @name: name of the builtin command
 * @function: a function ptr to the builtin
**/
typedef struct builtin_f
{
	char *name;
	int (*function)(char **argv, int status);
} builtin_d;


extern char **environ;


int main(int argc, char **argv);

void signal_handler(int sig_num);
int ash(void);


void prompt(void);
char *get_command(void);
char *handle_enter(char *string);
char *handle_space(char *string);
void handle_hashtag(char *buff);


int run_command(char **command);


char **separate_commands(char *input);
char **parse_command(char *input);


char *generate_command_path(const char *path, const char *command);
char *find_command_path(char *command);


void *ash_memcpy(char *dest, char *src, size_t size);
void *ash_realloc(void *ptr, size_t size);



int _putchar(char c);
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *str1, const char *str2, size_t n);


unsigned int compare_delim(char p, const char *str);
char *_strtok(char *str, const char *delim);

int ash_env(char **args, int status);
int convert_builtin(char **command, int status);
int check_builtin(char **command);

#endif
