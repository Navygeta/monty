#include "monty.h"

/**
 * opcode_pop - Removes top element in a stack
 * @stack: Pointer to the stack
 *@ line_number: unsigned int representing the line number
 */

void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_element = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		handle_exit_error();
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top_element);
}
