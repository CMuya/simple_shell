#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- function that reads text file
 * @filename: text file to read
 * @letters: number of letters to read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf_fer;
	ssize_t gq;
	ssize_t m;
	ssize_t t;

	gq = open(filename, O_RDONLY);
	if (gq == -1)
		return (0);
	buf_fer = malloc(sizeof(char) * letters);
	t = read(gq, buf_fer, letters);
	m = write(STDOUT_FILENO, buf_fer, t);

	free(buf_fer);
	close(gq);
	return (m);
}
