#include "shell.h"

/**
 * execute - executes argv from main
 * @exe: executable command
 * @envv: environ from child
 */
void execute(char **exe, char **envr)
{
	if (execve(exe[0], exe, envr) == -1)
	{
		exit(127);
	}

}
/**
 * forky - makes children
 * @arg: parent
 * @ennv: idk leave me alone
 */
void forky(char **arg, char **envs)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
		if (child == 0)
		{
			execute(arg, envs);
			exit(0);
		}
		else
		{
			waitpid(child, &status, WUNTRACED);
		}
}
