#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and print it to standard output .
 * @filename: A pointer to the name of the file.
 * @letters: number of letters it must read and print
 *
 * Return: the actual number of letters it could read and also print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t p, h, s;
	char *buffer;

	p = open(filename, O_RDONLY);
	if (p == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	s = read(p, buffer, letters);
	h = write(STDOUT_FILENO, buffer, s);

	free(buffer);
	close(p);
	return (h);
}
