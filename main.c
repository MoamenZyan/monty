#include "main.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument
 * Return: 0
*/

int main(int argc, char **argv)
{
	char buffer[100];
	stack_t *head = NULL;
	int line_number = 1;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		char *str = malloc(sizeof(char) * 100);

		str = trim_spaces(buffer);
		execute_opcode(str, &head, line_number);
		line_number++;
		free(str);
	}
	fclose(file);
	return (0);
}
