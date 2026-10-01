#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * close_file - closes file descriptors and handles errors
 * @fd: the file descriptor to be closed
 */
void close_file(int fd)
{
	int c;

	c = close(fd);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * check_io_status - checks if read/write operations failed
 * @stat: the result of the read/write operation
 * @filename: the name of the file
 * @mode: 'O' for opening/reading, 'W' for writing
 * @fd_from: file descriptor for reading
 * @fd_to: file descriptor for writing
 */
void check_io_status(int stat, char *filename, char mode,
		     int fd_from, int fd_to)
{
	if (mode == 'O' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			filename);
		exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		if (fd_from != -1)
			close_file(fd_from);
		if (fd_to != -1)
			close_file(fd_to);
		exit(99);
	}
}

/**
 * main - copies the contents of a file to another file
 * @argc: the number of arguments supplied to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, r, w;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	check_io_status(fd_from, argv[1], 'O', -1, -1);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	check_io_status(fd_to, argv[2], 'W', fd_from, -1);

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
			check_io_status(-1, argv[2], 'W', fd_from, fd_to);
	}

	check_io_status(r, argv[1], 'O', fd_from, fd_to);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
