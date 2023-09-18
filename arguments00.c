#include "shell.h"

/**
 * main - entry point
 * @argc: the number of arguments
 * @argv: arg vector
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[1])
{
	if (argc < 3)
	{
	printf("handle : %s<name\n", argv[0]);
	return (1);
	}
	printf("update, %s:\n", argv[1]);
	return (0);
}
