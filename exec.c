#include "main.h"
/**
 * exec - executes file
 * @argv: arguments and file to be executed
 * Return: 0 (on success)
 */
int exec(char **argv)
{
	pid_t pid_child;
	int status;

	if (strncmp("exit", argv[0], 4) == 0)
	{
		exit(-1);
	}
	pid_child = fork();

	if (pid_child == -1)
	{
		perror("Error");
		exit(1);
	}
	else if (pid_child == 0)
	{
		if ((execvp(argv[0], argv)) == -1)
		{
			return (-1);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
