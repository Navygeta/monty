#include "monty.h"

/**
 * free_it - Frees the stack
 * @top: Pointer to the head of the stack
 */
void free_it(stack_t *top)
{
	stack_t *temp;

	temp = top;
	while (top)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}
