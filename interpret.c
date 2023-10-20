#include "monty.h"
/**
* interpret - Monty language code interpreter
* @argc: Number of command line arguments
* @argv: Array of command line args strings
* Return: 0 on success, EXIt_FAILURE on failure
*/
cmdContext global_context = {NULL, NULL, NULL, 0};
int interpret_monty(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *monty_file;
	char *input;
	size_t size = 0;
	ssize_t get_input = 1;
	unsigned int counter = 0;

	if (argc != 2)
	{
		usage_err();
	}
	monty_file = open_monty_file(argv[1]);
	global_context.monty_file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (get_input > 0)
	{
		input = NULL;
		get_input = getline(&input, &size, monty_file);
		global_context.input = input;
		counter++;
		if (get_input > 0)
		{
			opcod_exec(input, &stack, counter, monty_file);
		}
		free(input);
	}
	free_it(stack);
	fclose(monty_file);
return (0);
}
