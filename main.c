#include "monty.h"

/**
 * main - main function
 * @argc: number of input command argument.
 * @argv: The command line arguments.
 * Return: 0 success and 1 otherwise.
*/

int main(int argc, char **argv)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	stack_t *stk = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		line_tokenizer(line, &stk, line_number);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

