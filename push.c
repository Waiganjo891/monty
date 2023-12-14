#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *next_token = strtok(NULL, " \n");
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (next_token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(next_token);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
