#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "monty.h"

/**
 * main - entry point
 *
 * @argc: the argument counter
 * @argv: variable containing a list of command line arguments
 *
 * Return: always return 0
*/

int main(int argc, char *argv[])
{
	const char *filename = argv[1];

	if (argc != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	monty(filename);

	return (0);
}

/**
 * monty - entry point before main
 *
 * @filename: the name of the file to read from
 *
 * Return: always return 0
*/

int monty(const char *filename)
{
	int i;
	char *buffer;
	char **lines, **instructs;
	stack_t **stack;

	stack = malloc(sizeof(stack_t) * 1024);

	buffer = read_file(filename);
	lines = parse(buffer, "\n");

	if (lines == NULL)
	{
		free(buffer);
		free(lines);
		exit(EXIT_SUCCESS);
	}

	for (i = 0; lines[i] != NULL; i++)
	{
		instructs = parse(lines[i], " ");
		if (instructs != NULL)
		{
			if (execute(stack, i + 1, instructs[0]) == 0)
				free(instructs);
			else
			{
				syntax_error(i + 1, instructs[0]);
				free(instructs);
				free(lines);
				free(buffer);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(lines);
	free(buffer);

	return (0);
}

/**
 * execute - validates and executes an instruction
 *
 * @stack: linked list to store values
 * @line_number: line number where an instruction was found
 * @opcode: the opcode to execute
 *
 * Return: return 0 on success
 *	   return 1 on failure
*/

int execute(stack_t **stack, int line_number, char *opcode)
{
	int i;
	instruction_t inst[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL},
	};

	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, inst[i].opcode) == 0)
		{
			inst[i].f(stack, line_number);
			return (0);
		}
	}
	return (1);
}
