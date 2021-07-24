#include "holberton.h"

/**
 * rev_string - will reverse a string
 * @s: the string to be reversed
 *
 * Return: doesn't
 */
void rev_string(char *s)
{
	char buf;
	int i;
	int len;

	for (len = 0; s[len] != '\0'; len++)
		continue;

	len--;

	for (i = 0; i <= len ; i++)
	{
		buf = s[len];
		s[len] = s[i];
		s[i] = buf;
		len--;
	}
}

/**
 * _strlen - will find the length of the string
 * @s: a pointer to the string
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (*s)
	{
		while (*(s + i) != '\0')
			i++;
	}

	return (i);
}
