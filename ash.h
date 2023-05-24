#ifndef ASH_SHELL
#define ASH_SHELL

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


extern char **environ;


int main(int argc, char **argv);


void ash(char **command);
void prompt(void);
char *get_command(void);
void parse_command(char *command, char **args);
int run_command(char **command);


char *generate_command_path(const char *path, const char *command);
char *find_command_path(char *command);



int _putchar(char c);
void update_lineptr(char **lineptr, size_t *n, ssize_t total_chars);
ssize_t ash_getline(char **lineptr, size_t *n, FILE *stream);
void *ash_memcpy(char *dest, char *src, size_t size);
void *ash_realloc(void *ptr, size_t size);


int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *str1, const char *str2, size_t n);

#endif
