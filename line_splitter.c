#include "monty.h"
/**
 * line_tokenizer - function with 3 arguments
 * @line:line string
 *@stk: stack argument
 * @line_number: line count
 *
 * Description: break up the buffer into tokens
 * Return: void
 */
void line_tokenizer(char *line, stack_t **stk, unsigned int line_number)
{
	char *string_token, *ins;

	string_token = strtok(line, DELIM);
	if (string_token == NULL || *string_token == ' ')
		return;
	if (*string_token == '\n' || *string_token == '#')
		return;
	if (strcmp(string_token, "push") == 0)
	{
		ins = string_token;
		string_token = strtok(NULL, DELIM);
		if (!is_digit(string_token))
		{
			line_number++;
			fprintf(stderr, "L%d: usage: push integer\n",
			line_number);
			exit(EXIT_FAILURE);
		}
		variables.temp = atoi(string_token);
		findOps(ins, stk, line_number);
	}
	else
		findOps(string_token, stk, line_number);
}

/**
 *  is_digit - checks if the string is a number
 * @string_token: the string being checked.
 *
 * Return: 1 if number, 0 if not.
 */
int is_digit(char *string_token)
{
	if (string_token == NULL)
		return (0);
	if (*string_token == '-')
		string_token++;
	while (*string_token != '\0')
	{
		if (isdigit(*string_token) == 0)
			return (0);
		string_token++;
	}
	string_token++;
	return (1);
}
