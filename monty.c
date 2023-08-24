#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monty.h"

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

	char *filename = malloc(sizeof(char) * BUFFER_SIZE);
	filename = argv[1];

	monty(filename);

	return (0);
}

int monty(char *filename)
{
	int i;
	char *buffer;
	char **lines, **instructs;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	lines = malloc(sizeof(char *) * BUFFER_SIZE);

	if (!buffer || !lines)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	buffer = read_file(filename);
	lines = parse(buffer, "\n");

	for (i = 0; lines[i] != NULL; i++)
	{
		instructs = malloc(sizeof(char *) * BUFFER_SIZE);
		instructs = parse(lines[i], " ");
		printf(instructs[0]);
		if (strcmp(instructs[0], "push") == 0)
			printf("Cool\n");
		else
			printf("Bad\n");
	}

	return (0);
}
