#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int len = 0;
	int i = 0;
	char temp;

	/* Step 1: Find the length of the string */
	while (s[len] != '\0')
	{
		len++;
	}

	/* Step 2: Swap characters from both ends towards the middle */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
