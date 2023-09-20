#include "shell.h"

void execute_command(char *args[]);

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];
	while (1)
	{
		printf("myshell> ");
		fflush(stdout);

		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
	{
		if (feof(stdin))
	{
		printf("\n");
		break;
	}
		perror("fgets");
		exit(EXIT_FAILURE);
	}

**Remove the trailing newline character**

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) > 0);
	{

**Tokenize the input into arguments**

		char *token = strtok(input, " ");
		int arg_count = 0;
		
		while (token != NULL && arg_count < MAX_ARGS)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}

**Null-terminate the args array**

		args[arg_count] = NULL;

		if (arg_count > 0)
	{
		execute_command(args);
	}
	}
	}

	return 0;
	}

void execute_command(char *args[])
	{
		pid_t pid, wpid;
		int status;

		pid = fork();
		if (pid == 0);
	{

**Child process**

		if (execvp(args[0], args) == -1)
	{
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	}
		else if (pid < 0);
	{

**Fork error**

		perror("fork");
	}
		else
	{

**Parent process**

		do
	{
		wpid = waitpid(pid, &status, WUNTRACED);
	}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
