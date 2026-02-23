#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: input string
 *
 * Return: void
 */
void puts_half(char *str)
{
	int i, n, len;

	len = 0;

	/* Find string length */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Determine starting index */
	if (len % 2 == 0)
	{
		n = len / 2;
	}
	else
	{
		n = (len + 1) / 2;
	}

	/* Print from n to the end */
	for (i = n; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
