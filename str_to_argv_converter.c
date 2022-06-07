#include "main.h"
/**
 * count_argv - counts number of words in a string
 * @s: string to be count
 * Return: number of words
 */
int count_argv(char *s)
{
	int cnt = 0;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == ' ')
		{
			cnt++;
		}
		i++;
	}
	return (cnt);
}
/**
 * str_to_argv - converts string to array of strings
 * @s: string to be  converted
 * Return: array of strings on success
 */
char **str_to_argv(char *s)
{
	int count = count_argv(s);
	char d[] = " ";
	char *p;
	char **arg = malloc((sizeof(char *) * (count + 1)));
	int i = 0;

	if (arg == NULL)
	{
		dprintf(2, "allocation of memory failed\n");
		exit(1);
	}
	p = strtok(s, d);
	while (p != NULL)
	{
		arg[i] = p;
		p = strtok(NULL, d);
		i++;
	}
	arg[i] = NULL;
	return (arg);
}
