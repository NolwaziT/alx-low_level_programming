#include "main.h"

/**
 * create_file - Create a new file or truncate an existing file with the given
 * filename and write the given text content to it.
 *
 * @filename: The name of the file to create or truncate.
 * @text_content: The text content to write to the file (may be NULL).
 *
 * Return: On success, returns 1. On failure, returns -1 and sets errno
 * appropriately.
 */

int create_file(const char *filename, char *text_content)
{
	int fd_new, w_new, len_new = 0;

	if (filename == NULL)
	return (-1);

	if (text_content != NULL)
	{
		for (len_new = 0; text_content[len_new];)
		len_new++;
	}

		fd_new = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
		w_new = write(fd_new, text_content, len_new);

		if (fd_new == -1 || w_new == -1)
		return (-1);

		close(fd_new);

			return (1);
}
