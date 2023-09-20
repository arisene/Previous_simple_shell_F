#include "shell.h"

/**
 * checkbuild - Check if the command is a built-in.
 * @arv: Array of arguments.
 * Return: Pointer to a function that takes arv and returns void.
 */
void (*checkbuild(char **arv))(char **arv)
{
	mybuild T[] = {
		{"exit", exitt},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (int i = 0; T[i].name; i++)
	{
		int j = 0;

		while (T[i].name[j] && T[i].name[j] == arv[0][j])

			j++;

		if (!T[i].name[j])
			return (T[i].func);
	}

	return (NULL);
}
