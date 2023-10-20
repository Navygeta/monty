#include "monty.h"

/**
 * opcode_swap - Swaps top two elements of the stack.
 * @top: Pointer to the top element of stack
 * @line_number: unsigned int representing line number
 * Return: Void
 */
void opcode_swap(stack_t **top, unsigned int line_number)
{
	stack_t *top_element;
	int len = 0, temp;

	for (top_element = *top; top_element; top_element = top_element->next)
	{
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		handle_exit_error(top);
	}

	top_element = *top;
	temp = top_element->n;
	top_element->n = top_element->next->n;
	top_element->next->n = temp;
}

