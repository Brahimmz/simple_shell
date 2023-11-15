#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define _GNU_SOURCE
#include <signal.h>
#include <errno.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0

extern char **environ;
/* shell.c */
char *pathfind(char *input);

/* execute.c */
void execute(char **exe, char **envr);
void forky(char **arg, char **envs);

/* string.c */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);

/* print.c */
void print_env(void);
int _putchar(int c);
void _puts(char *str);

/* getenv.c */
char *_getenv(const char *name);

#endif
