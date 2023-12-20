#include"main.h"
/**
 * pchar - A void
 * @stack: A stack_t
 * @line_number: An unsigned integer.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = pall(stack);
	printf("%c\n", value);
}
/**
 * push - A void
 * @stack: A stack_t
 * @n: An unsigned integer
 */
void push(stack_t **stack, unsigned int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
