#include "shell.h"
/**
 * _getenv - obviously gets environ
 * @name: name we're looking for
 * Return: value of env or 0
 */

char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (name == NULL)
	{
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
	if (name[j] == environ[i][j])
	{
		while (name[j])
		{
			if (name[j] != environ[i][j])
			{
				break;
			}
			j++;
		}
		if (name[j] == '\0')
		{
			value = (environ[i] + j + 1);
	return (value);
		}
	}
	}
	return (0);
}
