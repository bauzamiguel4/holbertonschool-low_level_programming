#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the integer value of the converted string
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int res = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			res = (res * 10) + (s[i] - '0');
			found = 1;
		}
		else if (found)
		{
			/* If we found numbers and now hit a non-number, stop */
			break;
		}
		i++;
	}

	return (res * sign);
}
