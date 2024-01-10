#include "monty.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line = NULL, *opcode;
	size_t len = 0;
	ssize_t read;
	instruction_t a[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode)
		{
			i = 0;
			while (a[i].opcode)
			{
				if (strcmp(opcode, a[i].opcode) == 0)
				{
					a[i].f(stack, *line_number);
					break;
				}
				i++;
			}
			if (!a[i].opcode)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", *line_number, opcode);
				free(line);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
