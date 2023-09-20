#include "shell.h"

/**
 * exit_shell - Exits the shell with an optional status code.
 * @args: Array of command arguments.
 */
void exit_shell(char **args)
{
	int status_code = (args[1]) ? atoi_positive(args[1]) : 0;
	free_args(args);

	exit((status_code < 0) ? 2 : status_code);
}

/**
 * atoi_positive - Converts a string to an integer.
 * @str: Pointer to the input string.
 * Return: The converted integer.
 */
int atoi_positive(char *str)
{
	int integer = 0, sign = 1, i = 0;

	while (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '\0')))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		integer = integer * 10 + (str[i++] - '0');
	}
	return (integer * sign);
}

/**
 * print_environment - Prints the current environment.
 * @args: Array of arguments (unused).
 */
void print_environment(char **args __attribute__ ((unused)))
{
	for (int i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}
}

/**
 * set_environment - Initialize or modify an environment variable.
 * @args: Array of command arguments.
 */
void set_environment(char **args)
{
	if (!args[1] || !args[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (int i = 0; environ[i]; i++)
	{
		int j = 0;
		while (args[1][j] && args[1][j] == environ[i][j])

			j++;

		if (args[1][j] == '\0')
		{
			for (int k = 0; args[2][k]; k++)
				environ[i][j + 1 + k] = args[2][k];
			environ[i][j + 1 + strlen(args[2])] = '\0';
			return;
		}
	}

	if (!environ[0])
	{
		environ[0] = concat_strings(args[1], "=", args[2]);
		environ[1] = NULL;
	}
}

/**
 * unset_environment - Remove an environment variable.
 * @args: Array of command arguments.
 */
void unset_environment(char **args)
{
	if (!args[1])
	{
		perror(_getenv("_"));
		return;
	}

	for (int i = 0; environ[i]; i++)
	{
		int j = 0;
		while (args[1][j] && args[1][j] == environ[i][j])

			j++;

		if (args[1][j] == '\0')
		{
			free(environ[i]);
			while (environ[i])
			{
				environ[i] = environ[i + 1];
				i++;
			}
			return;
		}
	}
}
