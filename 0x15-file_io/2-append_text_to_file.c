#include "main.h"

/**
 * append_text_to_file - Appends txt at the end of a file.
 * @filename: name of the file .
 * @text_content: txt content to be written
 *
 * Return: 1 for success and -1 for fail
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, h, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
	p = open(filename, O_WRONLY | O_APPEND);
	h = write(p, text_content, len);

	if (p == -1 || h == -1)
		return (-1);
	close(p);

	return (1);
}
