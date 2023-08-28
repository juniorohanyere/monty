#include <stdio.h>
#include <stdlib.h>

#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(1);
	}

	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}

	*stack = new;
}
