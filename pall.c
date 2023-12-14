#include "monty.h"
/**
 * pall - prints all values on the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the file
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
