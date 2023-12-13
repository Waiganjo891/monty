#include "monty.h"
/**
 * create_node - A stack_s
 * @n: An integer
 * Return: Always(New node)
 */
stack_s *create_node(int n)
{
	stack_s *new_node = malloc(sizeof(stack_s));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	return (new_node);
}
/**
 * push - A void
 * @stack: A stack_s
 * @n: An integer
 */
void push(stack_s **stack, int n)
{
	stack_s *new_node = create_node(n);

	new_node->next = *stack;
	*stack = new_node;
}
