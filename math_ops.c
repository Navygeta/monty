#include "monty.h"

/**
 * add_opcode - Adds top two elements in a stack.
 * @stack: Pointer to the top element of the stack
 * @line_number: Line number
 * Return: No return
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int len = 0, sum;

	while (top)
	{
		top = top->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		handle_exit_error(stack);
	}

	top = *stack;
	sum = top->n + top->next->n;
	top->next->n = sum;
	*stack = top->next;
	free(top);
}

