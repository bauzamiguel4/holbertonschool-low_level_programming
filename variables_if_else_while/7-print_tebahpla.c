#include <stdio.h>

/**
 * main - prints tebahapla
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int letra;

	for (letra = 'z'; letra >= 'a'; letra--)
	{
		putchar(letra);
	}
	putchar('\n');

	return (0);
}
