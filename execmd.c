#include "main.h"

/**
 * execmd - create child process to execute based on user input
 * @argv: pointer to array string elements
*/

void execmd(char **argv)
{
	int i, status, exitstatus = 0;
	char *command = NULL, *bin_path = NULL, *buffer;
	pid_t pid;

	pid = fork();
	if (argv)
	{
		if (pid == -1)
		{
			perror("page");
			exit(1);
		}
		if (pid == 0)
		{
		command = argv[0];
		bin_path = get_location(command);
		if (execve(bin_path, argv, environ) == -1)
		{
			perror("Error:");
			for (i = 0; argv[i]; i++)
				free(argv[i]);
				free(argv);
				free(buffer);
				exit(0);
		}
		}
		wait(&status);
		if (WIFEXITED(status))
		{
			exitstatus = WEXITSTATUS(status);
		}
		for (i = 0; argv[i]; i++)
		free(argv[i]);
		free(argv);
		free(buffer);
		return;
		}
}

