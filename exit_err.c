#include "monty.h"
/**
 * handle_exit_failure - Handles cleanup and exits on failure
 */
void handle_exit_error(stack_t **stack, FILE *file, char *input)
{
	(void)file;
	(void)input;

	fclose(global_context.monty_file);
	free(global_context.input);
	free_it(*stack);
	exit(EXIT_FAILURE);
}

