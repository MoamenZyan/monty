#include "main.h"

/**
 * execute_opcode - execution of opcode functions
 * @str: monty line
 * @head: head of the stack
 * @line_number: line number of the text
 * Return: void
*/
void execute_opcode(char *str, stack_t **head, int line_number)
{
	int i = 0, data;
	char *opcode, *value;
	instruction_t instructions[] = {
	{"push", push},
	{"pint", pint},
	{"pall", pall},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}
};
	opcode = strtok(str, " ");
	value = strtok(NULL, " ");
	if (value == NULL && strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (value == NULL)
			data = line_number;
		else
			data = atoi(value);
	}
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(head, data);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * add - adds last two element of the stack
 * @head: head of the stack
 * @value: line number of the text
 * Return: void
*/

void add(stack_t **head, int value)
{
	int temp;
	stack_t *current = *head;

	if (stack_len(*head) < 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", value);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
		current = current->next;
	temp = current->n + current->prev->n;
	current->prev->next = NULL;
	current->prev->n = temp;
}

/**
 * nop - function that does nothing :)
 * @head: head of the stack
 * @value: line number of the text
 * Return: void
*/

void nop(__attribute__((unused)) stack_t **head, __attribute__((unused)) int value)
{
}

/**
 * stack_len - function to calculate length of the stack
 * @head: head of the stack
 * Return: length of the stack
*/

int stack_len(stack_t *head)
{
	int i = 0;

	while (head->next != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

/**
 * *trim_spaces - function that cut off spaces from monty line
 * @input: text line
 * Return: the trimed text
*/

char *trim_spaces(const char *input)
{
	size_t start, end, trimmed_len;
	char *trimmed_str;
	
	if (input == NULL)
		return (NULL);


	start = strspn(input, " \t\r\n");
	end = strlen(input);

	while (end > start && isspace(input[end - 1]))
		end--;

	trimmed_len = (end > start) ? (end - start) : 0;
	trimmed_str = (char *)malloc(trimmed_len + 1);

	if (trimmed_str == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	strncpy(trimmed_str, input + start, trimmed_len);
	trimmed_str[trimmed_len] = '\0';
	return (trimmed_str);
}
