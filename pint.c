#include "monty.h"

/**
 * print_top - Prints element on top in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		freopen(NULL, "w", stdout);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
