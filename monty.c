/**
 * main - entry point
 *
 * @argc: the argument counter
 * @argv; variable containing a list of command line arguments
 *
 * Return: always return 0
*/

int main(int argc, char *argv[])
{
	monty();

	return (0);
}


/**
 * monty -
*/

int monty(char *filename)
{
	int file;
	/* open the file in read only mode */
	file = open(filename, O_RDONLY);

	/* check for error on opening file */
	if (file == -1)
	{
		access_error(filename);
		exit(EXIT_FAILURE);
	}

	/* read the opened file */
	rfile = read(file, buffer, BUFFER_SIZE);
	/* check for read error */
	if (rfile == -1)
	{
		access_error(filename);
		exit(EXIT_FAILURE);
	}
}
