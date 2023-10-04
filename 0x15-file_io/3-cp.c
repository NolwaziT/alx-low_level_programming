#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void check_IO_stat(int status, int fd, char *filename, char mode);

/**
 * main - copies the content of one file to another
 * @argc: argument count
 * @argv: arguments passed
 *
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, n_read = 1024, wrote, close_src, close_dest;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
	exit(97);
	}

	src_fd = open(argv[1], O_RDONLY);
	check_IO_stat(src_fd, -1, argv[1], 'O');

	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_IO_stat(dest_fd, -1, argv[2], 'W');

	while (n_read == 1024)
	{
	n_read = read(src_fd, buffer, sizeof(buffer));
			if (n_read == -1)

	check_IO_stat(-1, -1, argv[1], 'O');
	wrote = write(dest_fd, buffer, n_read);
	if (wrote == -1)
		check_IO_stat(-1, -1, argv[2], 'W');
	}

	close_src = close(src_fd);
	check_IO_stat(close_src, src_fd, NULL, 'C');

	close_dest = close(dest_fd);
	check_IO_stat(close_dest, dest_fd, NULL, 'C');

	return (0);
}

/**
 * check_IO_stat - checks if a file can be opened or closed
 * @status: file status
 * @fd: file descriptor
 * @filename: name of the file
 * @mode: closing or opening
 *
 * Return: void
 */
void check_IO_stat(int status, int fd, char *filename, char mode)
{
	if (mode == 'C' && status == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
	exit(100);
	}
	else if (mode == 'O' && status == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
	}
	else if (mode == 'W' && status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
