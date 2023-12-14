#include "monty.h"
/**
 * main - entry point for the program
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *opcode;
	FILE *file;
	unsigned int line_number = 0;
	size_t len = 0;
	ssize_t read;
	instruction_t i[] = {
                {"push", push},
                {"pall", pall},
                {NULL, NULL}
        };
	instruction_t *a;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&opcode, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(opcode, "\n");
		for (a = i; a->opcode != NULL; a++)
		{
			if (strcmp(opcode, a->opcode) == 0)
			{
				a->f(&stack, line_number);
				break;
			}
		}
		free(opcode);
		opcode = NULL;
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
