#include "main.h"


/**
 * sub - substracts last two element of the stack
 * @head: head of the stack
 * @value: line number of the text
 * Return: void
*/

void sub(stack_t **head, int value)
{
	int temp;
	stack_t *current = *head;

	if (stack_len(*head) < 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", value);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
		current = current->next;
	temp = current->prev->n - current->n;
	current->prev->next = NULL;
	current->prev->n = temp;
}


/**
 * _div - divides last two element of the stack
 * @head: head of the stack
 * @value: line number of the text
 * Return: void
*/

void _div(stack_t **head, int value)
{
	int temp;
	stack_t *current = *head;

	if (stack_len(*head) < 1)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", value);
		exit(EXIT_FAILURE);
	}

	while (current->next != NULL)
		current = current->next;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", value);
		exit(EXIT_FAILURE);
	}
	temp = current->prev->n / current->n;
	current->prev->next = NULL;
	current->prev->n = temp;
}


/**
 * mul - multiply last two element of the stack
 * @head: head of the stack
 * @value: line number of the text
 * Return: void
*/

void mul(stack_t **head, int value)
{
	int temp;
	stack_t *current = *head;

	if (stack_len(*head) < 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", value);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
		current = current->next;
	temp = current->prev->n * current->n;
	current->prev->next = NULL;
	current->prev->n = temp;
}
