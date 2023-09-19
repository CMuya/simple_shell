#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * Return: current environment
 */
int main(void)
{
       	if
	(argc != 1 || strncmp(argv[0], "env") != 0)
	{
	printf(stderr, "Used up: env\n");
        exit(1);
	}
	else
	{
	char **enviro = string; *enviro != NULL; enviro++) {
        printf("%s\n", *enviro);
	}
	return (0);
}
