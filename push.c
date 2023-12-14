#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t\r");
	int num;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (arg == NULL || (!isdigit(*arg) && *arg != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(arg);

	if (new_node == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
