#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

/**
 * change_directory - Change the current working directory.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: 0 on success, 1 on failure.
 */
int change_directory(int argc, char **argv)
{
	char *newDir = NULL;
	char currentDir[MAX_PATH_LENGTH];
	
	if (argc == 1)
	{
		newDir = getenv("HOME");
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1], "-") == 0)
		{
			newDir = getenv("OLDPWD");
			if (newDir == NULL)
			{
				printf("cd: OLDPWD not set\n");
				return (1);
			}
		}
		else
		{
			newDir = argv[1];
		}
	}
	else
	{
		printf("Usage: %s [DIRECTORY | -]\n", argv[0]);
		return (1);
	}

	if (getcwd(currentDir, sizeof(currentDir)) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	
	if (setenv("OLDPWD", currentDir, 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	
	if (chdir(newDir) != 0)
	{
		perror("chdir");
		return (1);
	}
	if (getcwd(currentDir, sizeof(currentDir)) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	
	if (setenv("PWD", currentDir, 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	return (0);
}

/**
 * main - Entry point.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
	return change_directory(argc, argv);
}

