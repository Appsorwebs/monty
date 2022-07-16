#include "monty.h"

int stack_len;

/**
 * main - main function to control all operations
 * @argc - argument counts
 * @argv - argument vector
 *
 * Return: 0 if success
 */

int main(int argc, char** argv)
{
	FILE *file;
	char *buff;
	char *opcode;
	size_t n;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	stack_len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &n, file) != -1)
	{
		line_number++;
		opcode = strtok(buff, "\n\t\r ");
		if (opcode != NULL && opcode[0] != '#')
		{
			get_func(opcode, &stack, line_number);
		}
	}
	free_all(&stack);

	fclose(file);

	return (0);
}
