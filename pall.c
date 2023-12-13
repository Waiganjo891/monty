#include "monty.h"
/**
 * pall - A void
 * @stack: A stacks
 */
void pall(stack_s *stack)
{
	stack_s *temp = stack;

	while (temp)
	{
		printf("%d\n", temp->data);
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
