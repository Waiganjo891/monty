#include "monty.h"
/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *arg;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n");
	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - Frees the memory allocated for the stack
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
}
/**
 * is_integer - An integer
 * @str: A constant character
 */
int is_integer(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str) && *str != '-' && *str != '+')
		{
			return 0;
		}
		str++;
	}
	return 1;
}
