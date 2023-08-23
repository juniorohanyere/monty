#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "monty.h"

/**
 * access_error - prints an error message to the stderr when a file cannot
 *		  be opened or read
 *
 * @filename: the name of the file that cannot be accessed
 *
 * Return: return nothing
*/

void access_error(char *filename)
{
	/* print to the POSIX standard error */
	dprintf(STDERR_FILENO, "Error: Can't open file %s", filename);
}

/**
 * syntax_error - prints an error message to the stderr when a monty bytecode
 *		  contains a bad instruction
 *
 * @line_number: the line number where the instruction appears
 * @opcode: the bad instruction
 *
 * Return: return nothing
*/

void syntax_error(int line_number, char *opcode)
{
	/* 2 is also same as STDERR_FILENO */
	dprintf(2, "L%s: unknown instruction %s", line_number, opcode);
}

/**
 * malloc_error - prints an error message to the stderr when there's a malloc
 *		  failure
 *
 * Return: return nothing
*/

void malloc_error(void)
{
	printf("Error: malloc failed");
}
