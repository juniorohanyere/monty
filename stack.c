#include <stdio.h>
#include <stdlib.h>

#include "monty.h"

/**
 * push - function that pushes an integer unto a stack
 *
 * @stack: the stack
 * @line_number: the line number from which an line of code executes
 *
 * Return: return nothing
*/

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

/**
 * pall - function that prints all integer found in a stack
 *
 * @stack: the stack
 * @line_number: the line number from which an line of code executes
 *
 * Return: return nothing
*/

void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
