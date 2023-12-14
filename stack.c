#include "main.h"


static int stack_size;

/**
 * push - function to push elements to the stack
 * @head: head of the stack
 * @n: value of the element
 * Return: void
*/

void push(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *head;

	stack_size++;
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
	{
		*head = new;
		return;
	}

	while (current->next != NULL)
		current = current->next;

	current->next = new;
	new->prev = current;
}

/**
 * pop - function to pop elements from the stack
 * @head: head of the stack
 * @value: line number of the stack
 * Return: void
*/

void pop(stack_t **head, int value)
{
	stack_t *current = *head;

	stack_size--;
	if (stack_size <= -1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", value);
		exit(EXIT_FAILURE);
	}
	if (current->next == NULL)
	{
		free(current);
		*head = NULL;
		return;
	}
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;

}

/**
 * pall - function to pop elements from the stack
 * @head: head of the stack
 * @value: line number of the stack
 * Return: void
*/

void pall(stack_t **head, __attribute__((unused)) int value)
{
	stack_t *current = *head;

	if (*head == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}

/**
 * pint - function to get the last element of the stack
 * @head: head of the stack
 * @value: line number of the stack
 * Return: void
*/

void pint(stack_t **head, int value)
{
	stack_t *current = *head;

	if (stack_size == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", value);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
		current = current->next;
	printf("%d\n", current->n);
}

/**
 * swap - function to top two elements of the stack
 * @head: head of the stack
 * @value: line number of the stack
 * Return: void
*/

void swap(stack_t **head, int value)
{
	int temp;
	stack_t *current = *head;

	if (stack_len(*head) < 1)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", value);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
		current = current->next;
	temp = (current->prev)->n;
	(current->prev)->n = current->n;
	current->n = temp;
}
