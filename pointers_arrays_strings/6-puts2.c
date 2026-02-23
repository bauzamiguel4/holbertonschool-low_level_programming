#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: input string
 *
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;
	int len = 0;

	/* Find the length of the string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Print characters at indices 0, 2, 4... */
	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
