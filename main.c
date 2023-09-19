#include "main.h"

int main(int ac, char **argv){

	char *prompt = "(KSHELL) &";
	char *lineptr= NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nc_reads;
	char *token;
	const char *delim = " \n";
	int i = 0;
	int num_tokens = 0;

	(void)ac; 

	while(1){


		printf("%s ", prompt);
		nc_reads = getline(&lineptr, &n, stdin);

		/*check for EOF*/
		if (nc_reads == -1){
			printf("Time to sleep...\n");
			return(-1);
		}

		/* allocate memory for lineptr copy*/
		lineptr_copy = malloc(sizeof(char) * nc_reads);
		if(lineptr_copy == NULL){
			perror("tsh:Memory allocation error");
			return(-1);
		}
		/* making a copy of lineptr*/
		strcpy(lineptr_copy, lineptr);
		/* split lineptr into an  array*/ 
		token = str_tok(lineptr, delim);

		while(token != NULL){
			num_tokens++;
			token = str_tok(NULL, delim);
		}
		num_tokens++;

		/* allocate memeory to the array*/

		argv = malloc(sizeof(char *) * num_tokens);

		token = str_tok(lineptr_copy, delim);

		for(i= 0; token != NULL ; i++){
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token= str_tok(NULL, delim);
		}
		argv[i] = NULL;

		/*execute  command*/
		execmd(argv);
	}

	/* free the allocated memory*/
	free(lineptr_copy);
        free(lineptr);


	return(0);
}
