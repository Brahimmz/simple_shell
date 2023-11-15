#include "shell.h"
/**
 * pathfinder - a truck, joking it looks for the path
 * @input: command to be looked for
 * Return: full path
 */
char *pathfind(char *input)
{
	char *path_env = _getenv("PATH");
	char *path_copy = _strdup(path_env);
	char *path_dir = NULL, *full = NULL;
	char *full_path = malloc(_strlen(input) + 20);

	if (access(input, F_OK) == 0)
	{
		free(path_copy);
		free(full_path);
		return (_strdup(input));
	}
	if (full_path == NULL)
	{
		perror("malloc fullpath error");
		exit(124);
	}
	if (path_copy == NULL)
	{	perror("strdup error");
		exit(124); }

	path_dir = strtok(path_copy, ":");
	while (path_dir)
	{	full_path[0] = '\0';
		_strcpy(full_path, path_dir);
		_strcat(full_path, "/");
		_strcat(full_path, input);

		if (access(full_path, F_OK) == 0)
		{	full = _strdup(full_path);
			free(path_copy);
			free(full_path);
			return (full); }

		path_dir = strtok(NULL, ":"); }
	free(full);
	free(full_path);
	free(path_copy);
	return (NULL);
}
