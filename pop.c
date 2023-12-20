#include"main.h"
/**
 * pall - An integer
 * @stack: A stack_t
 * Return: (Value)
 */
int pall(stack_t **stack)
{
	int value;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return (0);
	}
	temp = *stack;
	value = temp->n;
	*stack = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	free(temp);
	return (value);
}
/**
 * free_stack - A void
 * @stack: A stack_t
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
