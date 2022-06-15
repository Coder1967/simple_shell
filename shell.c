#include "main.h"

/**
 *  main - function which calls other function as
 * well as receives arguments for shell
 * @argv: command line arguments
 * @argc: number of command line arguments
 * Return: 0(on success)
 */
int main(int argc, char **argv)
{
	int confirmation;
	char **tokens;
	size_t bufsize = BUFSIZ;
	char *buffer;
	int pipe = 0;

	if (argc >= 2)
	{
		if (execve(argv[1], argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(-1);
		}
		return (0);
	}
	buffer = (char *)malloc((bufsize * sizeof(char)));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	do {
		if (isatty(fileno(stdin)))
		{
			pipe = 1;
			printf("#cisfun$ ");
		}
		getline(&buffer, &bufsize, stdin);
		buffer[strlen(buffer) - 1] = '\0';
		tokens = str_to_argv(buffer);
		confirmation = exec(tokens);
		if (confirmation == -1)
		{
			perror(argv[0]);
		}
	} while (pipe && confirmation != -1);
	return (0);
}
