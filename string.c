#include "shell.h"

/**
 * _strdup - Duplicate a string in newly allocated memory.
 * @str: Pointer to the string to duplicate.
 * Return: Pointer to the duplicated string or NULL on failure.
 */
char *_strdup(char *str)
{
	if (!str)
		return (NULL);

	int length = _strlen(str);
	char *new = malloc(length + 1);

	if (!new)
		return (NULL);

	for (int i = 0; i <= length; i++)
		new[i] = str[i];

	return (new);
}

/**
 * concat_all - Concatenate three strings into a newly allocated memory.
 * @name: First string.
 * @sep: Second string.
 * @value: Third string.
 * Return: Pointer to the new string or NULL on failure.
 */
char *concat_all(char *name, char *sep, char *value)
{
	int len1 = _strlen(name);
	int len2 = _strlen(sep);
	int len3 = _strlen(value);
	int total_len = len1 + len2 + len3 + 1;

	char *result = malloc(total_len);

	if (!result)
		return (NULL);

	int i, k = 0;

	for (i = 0; i < len1; i++)
		result[k++] = name[i];

	for (i = 0; i < len2; i++)
		result[k++] = sep[i];

	for (i = 0; i < len3; i++)
		result[k++] = value[i];

	result[k] = '\0';

	return (result);
}

/**
 * _strlen - Calculate the length of a string.
 * @s: Pointer to the string.
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;

	return (length);
}

/**
 * _putchar - Write a character to stdout.
 * @c: The character to print.
 * Return: On success, return 1. On error, return -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Print a string.
 * @str: Pointer to the string.
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
}
