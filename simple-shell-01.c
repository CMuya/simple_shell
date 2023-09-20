#include "shell.h"

#define MAX_COMMAND_LENGTH 1024

void execute_command(char *command);

int main(void);

/**
 * execute_command - Execute given command
 * @command: The command to execute.
 */

void execute_command(char *command)
	{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
/* Child process */
	if (execlp(command, command, (char *)NULL) == -1)
	{
	perror(command);
	exit(EXIT_FAILURE);
	}
	}
	else if (pid < 0)
	{
/* Fork error */
	perror("fork");
	}
	else
	{
/* Parent process */
	do
	{
		wpid = waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
	printf("simple_shell> ");
	fflush(stdout);

	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
/* End of error */
		if (feof(stdin))
		{
		printf("\n");
		break;
		}
		perror("fgets");
		exit(EXIT_FAILURE);
	}
/* Remove the trailing newline character */
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) > 0)
		{
		execute_command(command);
		}
	}

	return (0);
}
