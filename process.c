#include "monty.h"
/**
 * process_instructions - A void
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 */
void process_instructions(stack_t **stack, unsigned int *line_number)
{
	FILE *file;
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
}
