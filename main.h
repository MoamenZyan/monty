#ifndef MAIN_H
#define MAIN_H


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, int line_number);
} instruction_t;

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void pop(stack_t **head, int value);

void push(stack_t **head, int value);

void pall(stack_t **head, int value);

void pint(stack_t **head, int value);

void swap(stack_t **head, int value);

void add(stack_t **head, int value);

void nop(stack_t **head, int value);

void execute_opcode(char *str, stack_t **head, int line_number);

char *trim_spaces(const char *input);

int stack_len(stack_t *head);

#endif
