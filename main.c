#include "monty.h"

var_t var;

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings representing the command-line arguments
 * Return: 0 on success, or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file_path;
	char line[MAX];
	stack_t *stack = NULL;

	var.line = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_path = fopen(argv[1], "r");

	if (file_path == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	var.args = malloc(sizeof(char *) * 2);
	if (var.args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX, file_path))
	{
		check_line(line, &stack);
		var.line++;
	}
	fclose(file_path);
	free(var.args);
	free_stack(&stack);
	return (0);
}
