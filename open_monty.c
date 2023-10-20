#include "monty.h"

/**
 * open_monty_file - Function to open monty file
 *@filename: File to be opened
 * Return: The file
 */

FILE *open_monty_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (file);
}
