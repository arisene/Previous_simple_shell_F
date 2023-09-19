#include "main.h"

char *get_location(char *command){
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	/*create a duplicate for path*/
	if(path){

		path_copy = strdup(path);
		/* get the length of the command*/
		command_length = strlen(command);
		/* break down the path into tokens*/
		path_token = str_tok(path_copy, ":");

		while(path_token != NULL){
			/*get the length */
			directory_length = strlen(path_token);
			/* allocate memory */
			file_path = malloc(command_length + directory_length + 2);
			/*build the path for the command*/

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			/* test out the file path*/

			if(stat(file_path, &buffer) == 0){

				free(path_copy);

				return (file_path);
			}else{
				free(file_path);
				path_token = str_tok(NULL, ":");
			}
		}

		/* free memory in case we don't get file path*/
		free(path_copy);
		/* test before we exit*/
		if(stat(command, &buffer) == 0)
		{
			return (command);
		}

		return (NULL);

	}

	return(NULL);

}
