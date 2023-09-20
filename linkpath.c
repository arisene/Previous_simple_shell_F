#include "shell.h"

/**
 * _getenv - Get the value of the global variable.
 * @name: Name of the global variable.
 * Return: String value or NULL.
 */
char *_getenv(const char *name)
{
	if (!name)
		return (NULL);

	for (int i = 0; environ[i]; i++)
	{
		int j = 0;

		if (name[j] == environ[i][j])
		{
			while (name[j] && name[j] == environ[i][j])
				j++;

			if (!name[j])
				return (environ[i] + j + 1);
		}
	}

	return (NULL);
}

/**
 * add_node_end - Add a new node at the end of a linked list.
 * @head: Pointer to the pointer to the linked list.
 * @str: String to add to the list.
 * Return: Address of the new node.
 */
list_path *add_node_end(list_path **head, char *str)
{
	if (!new || !str)
		return (NULL);

	list_path *new = malloc(sizeof(list_path));

	if (!new)
		return (NULL);

	new->dir = str;
	new->p = NULL;

	if (!*head)
		*head = new;
	else
	{
		list_path *tmp = *head;

		while (tmp->p)
			tmp = tmp->p;
		tmp->p = new;
	}

	return (*head);
}

/**
 * linkpath - Create a linked list for path directories.
 * @path: String of path value.
 * Return: Pointer to the created linked list.
 */
list_path *linkpath(char *path)
{
	list_path *head = NULL;
	char *token;
	char *cpath = _strdup(path);

	token = strtok(cpath, ":");
	while (token)
	{
		head = add_node_end(&head, token);
		token = strtok(NULL, ":");
	}

	return (head);
}

/**
 * _which - Find the pathname of a filename.
 * @filename: Name of file or command.
 * @head: Head of linked list of path directories.
 * Return: Pathname of filename or NULL if no match.
 */
char *_which(char *filename, list_path *head)
{
	struct stat st;

	list_path *tmp = head;

	while (tmp)
	{

		char *string = concat_all(tmp->dir, "/", filename);
		if (stat(string, &st) == 0)
			
		{
			return (string);
		}
		free(string);
		tmp = tmp->p;
	}

	return (NULL);
}

/**
 * free_list - Free a linked list.
 * @head: Pointer to the linked list.
 */
void free_list(list_path *head)
{
	while (head)
		
	{
		list_path *storage = head->p;

		free(head->dir);
		free(head);
		head = storage;
	}
}
