#include"main.h"
/**
 * execute_opcode - An execution of the opcode.
 * @stack: A stack_t
 * @line_number: An unsigned integer.
 * @opcode: A character
 */
void execute_opcode(stack_t **stack, unsigned int line_number, char *opcode)
{
	char *arg;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (arg == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(arg));
	}
	else if (strcmp(opcode, "pchar") == 0)
	{
		pchar(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
