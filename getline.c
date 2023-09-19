#include "shell.h"
/**
 * main - entry point
 * Return: the line gotten
 */
#define MAX_BUFFER_SIZE 1024

static char buffer[MAX_BUFFER_SIZE];
static size_t buffer_size = 0;
static size_t buffer_pos = 0;
ssize_t custom_getline(char **lineptr, size_t *n) 
{
    if (lineptr == NULL || n == NULL)
        {
	return -1;
    }
    size_t line_length = 0;
    ssize_t bytes_read;
    if (buffer_pos >= buffer_size) 
    {
        bytes_read = read(STDIN_FILENO, buffer, MAX_BUFFER_SIZE);

        if (bytes_read <= 0)
	{
            return bytes_read;
        }

        buffer_size = (size_t)bytes_read;
        buffer_pos = 0;
    }
    if (*lineptr == NULL || *n < line_length + buffer_size) 
    {
        *n = line_length + buffer_size + 1;  
        *lineptr = (char *)realloc(*lineptr, *n);
        if (*lineptr == NULL) {
            return -1;  
        }
    }

    while (buffer_pos < buffer_size) {
        (*lineptr)[line_length++] = buffer[buffer_pos++];
        if ((*lineptr)[line_length - 1] == '\n') {
            (*lineptr)[line_length] = '\0';
            return line_length;
        }
    }
    ssize_t additional_bytes = custom_getline(lineptr, n);
    if (additional_bytes > 0) {
        line_length += additional_bytes;
    }

    return line_length;
}

int main() 
{
    char *line = NULL;
    size_t line_length = 0;

    while (1) {
        ssize_t bytes_read = custom_getline(&line, &line_length);

        if (bytes_read <= 0) {
 
            break;
        }
        printf("Line: %s", line);
    }
    free(line);
    return 0;
}
