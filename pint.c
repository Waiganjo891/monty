#include "monty.h"
/**
 * pint - Prints the value at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - checks if the stack is empty
 * @stack: A stack_t
 * @line_number: An unsigned integer
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
/**
 * swap - It checks if the stack contains at least two elements
 * @stack: A stact_t
 * @line_number: An unsigned integer
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1 = *stack;
	stack_t *temp2 = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp1->next = temp2->next;
	temp2->prev = temp1->prev;
	temp1->prev = temp2;
	temp2->next = temp1;
	*stack = temp2;
}
