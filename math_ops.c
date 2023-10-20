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

/**
 * sub_opcode - Opcode Subtraction
 * @top: Pointer to top of stack
 * @counter: Line number
 * Return: Void
 */
void sub_opcode(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int result, nodes;

	temp = *top;

	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		handle_exit_error(top);
	}

	temp = *top;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*top = temp->next;
	free(temp);
}

