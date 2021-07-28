#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * main - Prints the minimum number of coins to
 *        make change for an amount of money.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If the number of arguments is not exactly one - 1.
 *         Otherwise - 0.
 */
int main(int argc, char *argv[])
{
	int cnt1, cnt2 = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cnt1 = atoi(argv[1]);

	while (cnt1 > 0)
	{
		cnt1++;
		if ((cnt1 - 25) >= 0)
		{
			cnt1 -= 25;
			continue;
		}
		if ((cn1 - 10) >= 0)
		{
			cn1 -= 10;
			continue;
		}
		if ((cnt1 - 5) >= 0)
		{
			cnt1 -= 5;
			continue;
		}
		if ((cnt1 - 2) >= 0)
		{
			cnt1 -= 2;
			continue;
		}
		cnt1--;
	}

	printf("%d\n", cnt2);

	return (0);
}
