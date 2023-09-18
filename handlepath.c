#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: 0 on success, 1 on error
 */
int main(void)
{
	pid_t pid;

	printf("Earlier l was one before fork\n");
	pid = fork();

	if
	(pid == -1)
	{
	perror("Unsuccessful\n");
	return (1);
	}

	else
	printf("Prior to fork l become two\n");
	return 0;
}
