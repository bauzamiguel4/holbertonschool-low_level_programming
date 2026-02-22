#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14
 *
 * Return: void
 */
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j > 9)
			{
				_putchar((j / 10) + '0'); /* 1st use: Prints '1' for 10-14 */
			}
			_putchar((j % 10) + '0'); /* 2nd use: Prints units 0-9 */
		}
		_putchar('\n'); /* 3rd use: New line after each set */
	}
}
