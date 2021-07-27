#include "holberton.h"

/**
 *
 */

int _printf(const char spec)
{
	int i = 0;

	for ( ; spec[i] != '\0'; i++)
	{
		if (spec[i].sym == spec)
			break;
		return (spec[i].printf_t);
	}
	putchar ('\n');
	return (0)
}

/**
 * _printf - Will perform formatted printing with any number of arguments
 * @format: format string to use for printing
 *
 * Return: always 0
 */
int _printf(const char *format, ...)
{
	int x = 0;
	int count = 0;


	for ( ; format[x] != '\0'; x++)
	{
		if (format[x] == '%' && format[x + 1] != '\0')
		{
			function = printf_t(format[x + 1])
		}
		putchar (format[x]);
		count++;
	}
	/*for ( ; format[x + 1] == 'c' || format[x + 1] == 's'; x++)
	{
		if (format != "%")
			break;
		putchar (format[x]);
		return (x);
	}*/
	putchar ('\n');
	return (count);
}
