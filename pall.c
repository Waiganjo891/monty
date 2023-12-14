#include "monty.h"
/**
 * pall - prints all values on the stack
 * @stack: pointer to the head of the stack
 */
void pall(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push_opcode - A void
 * @stack: A stack_s
 * @line: A character
 * @line_number: An integer
 */
void push_opcode(stack_s **stack, char *line, int line_number)
{
	int data = atoi(line);

	if (data == 0 && strcmp(line, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, data);
}
