#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *num_str;
	int num;
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "L%d: Stack not initialized\n", line_number);
		exit(EXIT_FAILURE);
	}
	num_str = strtok(NULL, " ");

	if (!num_str || !isdigit(*num_str))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(num_str);
	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
