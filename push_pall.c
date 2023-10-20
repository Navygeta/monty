#include "monty.h"

/**
 * push_element - Inserts an element onto a stack
 * @stack: Stack pointer
 * @n: The data or integer value to push onto the stack
 */
void push_element(stack_t **stack, unsigned int line_number)
{
	stack_t *nu_nod = malloc(sizeof(stack_t));
	(void)line_number; /*Parameter not used*/

	if (nu_nod == NULL)
	{
		perror("Error: Memory allocation failed\n");
		handle_exit_error(stack);
	}

	nu_nod->n = atoi(global_context.arg);
	nu_nod->prev = NULL;
	nu_nod->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = nu_nod;
	}

	*stack = nu_nod;
}

/**
 * traverse_pall - Traverses and displays all values in the stack
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: Unsigned int representing line number
 */
void traverse_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr_nod = *stack;
	(void)line_number; /* Parameter not used*/

	while (curr_nod != NULL)
	{
		printf("%d\n", curr_nod->n);
		curr_nod = curr_nod->next;
	}
}
