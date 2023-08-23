/**
 * read_file - reads the content of a file
 *
 * @filename: the file to read from
 *
 * Description: reads the content of @filename and assigns the buffer to a
 *		char pointer variable. @filename is an argument from
 *		the command line
 *
 * Return: return the buffer read from @filename
*/

char *read_file(char *filename)
{
	int file, rfile;
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);

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
	close(file);

	return (buffer);
}

/**
 * parser - parses a buffer into lines if the buffer contains new lines
 *
 * @buffer: the buffer to be parsed
 *
 * Return: return an array of the parsed buffer in form of lines
*/

char **parser(char *buffer)
{
	int i, buffer_size = BUFFER_SIZE;
	char *token;
	char **tokens;

	tokens = malloc(sizeof(char *) * buffer_size);
	if (!tokens)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	token = strtok(line, "\n");
	if (token == NULL)
		return (NULL);

	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		if (i >= buffer_size)
		{
			/* realloc */
			buffer_size += BUFFER_SIZE;
			tokens = _realloc(tokens,
				buffer_size  * sizeof(char *));
			if (!tokens)
			{
				malloc_error();
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
	}
	/* null termination */
	tokens[i] = NULL;

	free(token);

	return (tokens);
}
