#include "shell.h"

/**
 * splitstring - Split a string into an array of pointers to words.
 * @str: The string to be split.
 * @delim: The delimiter.
 * Return: Array of pointers to words.
 */
char **splitstring(char *str, const char *delim)
{
	int i = 0, wn = 2;
	char **array = NULL;
	char *token, *copy = _strdup(str);

	if (!copy)
	{
		perror(_getenv("_"));
		return (NULL);
	}

	token = strtok(copy, delim);
	array = malloc(sizeof(char *) * wn);
	array[0] = _strdup(token);

	while (token)
	{
		token = strtok(NULL, delim);
		if (token)
			array = _realloc(array, sizeof(char *) * wn++, sizeof(char *) * wn);
		if (token)
			array[i++] = _strdup(token);
	}

	free(copy);
	return (array);
}

/**
 * execute - Execute a command.
 * @argv: Array of arguments.
 */
void execute(char **argv)
{
	int d, status;

	if (!argv || !argv[0])
		return;

	d = fork();
	if (d == -1)
	{
		perror(_getenv("_"));
	}

	if (d == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}

	wait(&status);
}

/**
 * _realloc - Reallocate memory block.
 * @ptr: Previous pointer.
 * @old_size: Old size of the previous pointer.
 * @new_size: New size for our pointer.
 * Return: New resized pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new, *old;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	old = ptr;
	if (new == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		new[i] = old[i];

	free(ptr);
	return (new);
}

/**
 * freearv - Free the array of pointers arv.
 * @arv: Array of pointers.
 */
void freearv(char **arv)
{
	int i;

	for (i = 0; arv && arv[i]; i++)
		free(arv[i]);
	free(arv);
}
