#include "main.h"
/**
 * main - shell program entry point
 * @ac: arg count
 * @argv: arg vector
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **argv)
{
	char *token, *buff = NULL, *input_copy = NULL, *line = NULL;
	size_t length = 0;
	ssize_t input;
	const char *delim = " \n";
	int exitstatus = 0, token_no = 0;

	while (1)
	{
		do {
			printf("Shell$ ");
			input = getline(&buff, &length, stdin);
			if (input == -1)
			{
				printf("Exiting shell....\n");
				return (-1);
			}
			input_copy = malloc(sizeof(char) * input);
			if (input_copy == NULL)
			{
				perror("Error with input");
				return (-1);
			}
			strcpy(input_copy, buff);

			argv = malloc(sizeof(char *) * token_no);
			token = strtok(input_copy, delim);
			for (ac = 0; token != NULL; ac++)
			{
				argv[ac] = malloc(sizeof(char) * strlen(token));
				strcpy(argv[ac], token);
				token = strtok(NULL, delim);
			}
			argv[ac] = NULL;
			execmd(argv);
			} while (input != '\0');
			free(input_copy);
			free(buff);

			return (0);
}
}

