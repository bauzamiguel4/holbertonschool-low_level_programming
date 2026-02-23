#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: the source string to append
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* Find the end of dest string */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Append src to dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add the final null terminator */
	dest[i] = '\0';

	return (dest);
}
