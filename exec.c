#include "monty.h"
/**
* opcod_exec - Executes the opcode commands
* @stack: Pointer to top of stack
* @lineNum: Line counter
* @file: Monty file pointer
* @input: opcode input
* Return: Void
*/
int opcod_exec(char *input, stack_t **stack, unsigned int lineNum, FILE *file)
{
	unsigned int i;
	char *current_opcode;
	instruction_t op_dict[] = {
				{"push", push_element}, {"pall", traverse_pall},
				{"pint", print_top}, {"pop", opcode_pop},
				{"swap", opcode_swap}, {"nop", no_operation},
				{"add", add_opcode}, {"sub", sub_opcode},
				{"div", div_opcode}, {"mod", mod_opcode},
				{NULL, NULL}
				};

	current_opcode = strtok(input, OP_DELIM);
	if (current_opcode && current_opcode[0] == '#')
		return (0);
	global_context.arg = strtok(NULL, OP_DELIM);

	for (i = 0; op_dict[i].opcode; i++)
	{
		if (strcmp(current_opcode, op_dict[i].opcode) == 0)
		{
			op_dict[i].f(stack, lineNum);
			return (0);
		}
	}
	if (current_opcode && op_dict[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, current_opcode);
		fclose(file);
		free(input);
		free_it(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
