#include "shell.h"
#include <stdio.h>
/**
* main - entry point
* @argc: the number of arguments
* @argv: arg vector
* Return: 0 on success, 1 on error
*/
int main(int argc, char **argv) 
{
	int i
	printf("argc: %d\n", argc);
	for (int i = 0; argv[1] != NULL; i++)
	printf("argv[%d]: %s\n", i, argv[1]);
	return 0;
}
