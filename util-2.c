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
 * rot13 - will convert a string with rot13
 * @str: string to be processed
 *
 * Return: pointer to the processed string
 */
char *rot13(char *str)
{
	int x, y;
	char *com[2] = {"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ",
		"nNoOpPqQrRsStTuUvVwWxXyYzZaAbBcCdDeEfFgGhHiIjJkKlLmM"};

	for (x = 0; *(str + x) != '\0'; x++)
	{
		for (y = 0; com[0][y]; y++)
		{
			if (*(com[0] + y) == *(str + x))
			{
				*(str + x) = *(com[1] + y);
				break;
			}
		}
	}

	return (str);
}

/**
 * _strdup - will malloc a space in memory and copy a string to it
 * @str: string to copy
 *
 * Return: a pointer pointing to the created string
 */
char *_strdup(char *str)
{
	int l = 1, i = 0;
	char *cpy;

	if (str == NULL)
		return (NULL);

	while (*(str + l) != '\0')
		l++;

	cpy = malloc((sizeof(char) * l) + 1);
	if (cpy == NULL)
		return (NULL);
	do {
		*(cpy + i) = *(str);
		i++;
		str++;
	} while (*(str - 1) != '\0');

	return (cpy);
}
