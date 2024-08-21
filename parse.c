#include "main.h"

#define MAX_ARGS 64  /* Maximum number of arguments */

char **parse_command(char *command)
{
	char **argv;
	char *token;
	int argc = 0;

	/* Allocate memory for the maximum number of arguments */
	argv = malloc(MAX_ARGS * sizeof(char *));
	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Tokenize the input command string */
	token = strtok(command, " ");
	while (token != NULL && argc < MAX_ARGS - 1)
	{
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;  /* NULL-terminate the array */

	return (argv);
}
