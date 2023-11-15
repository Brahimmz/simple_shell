#include "shell.h"

/**
 * main - the program main
 * Return: 1 0
 */
int main(void)
{
	char *kptr, *argv[7], *full_path = NULL, *input = NULL;
	size_t n = 0;
	ssize_t gln;
	int i = 0;

	while (1)
	{
		isatty(STDIN_FILENO) ? write(STDOUT_FILENO, "$ ", 2) : 0;
		gln = getline(&input, &n, stdin);
		if (gln == -1 || _strcmp(input, "exit\n") == 0)
		{ argv[0] = NULL;
			break; }
		if (_strcmp(input, "env\n") == 0)
		{ print_env();
			continue; }
		gln > 0 ? input[gln - 1] = '\0' : 0;
		for (i = 0; (kptr = strtok(i == 0 ? input : NULL, " ")); i++)
		{ argv[i] = kptr; }
		argv[i] = NULL;
		if (argv[0] == NULL || _strcmp(argv[0], "\t") == 0)
		{continue; }
		full_path = pathfind(argv[0]);
		if (full_path != NULL)
		{argv[0] = _strdup(full_path); }
		else
		{ perror(argv[0]);
			continue; }
		free(full_path);
		forky(argv, environ);
		free(argv[0]); }
	free(input);
	return (0); 
}
