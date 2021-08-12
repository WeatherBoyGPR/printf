#include "holberton.h"

/**
 * mod_specprint - will print a percentage sign
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 * Return: The count of characters printed.
 */
int mod_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return (con);

	_putchar('%');

	return (con + 1);
}

/**
 * s_specprint - will print a variable of type string
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 * Return: The count of carachters printed.
 */
int s_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	char *s, *err = "(null)";

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return (con);

	s = va_arg(args, char *);
	if (s == NULL)
	{
		write(1, err, _strlen(err));
		return (con + _strlen(err));
	}

	write(1, s, _strlen(s));

	return (con + _strlen(s));
}

/**
 * c_specprint - will print a variable of type char
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 * Return: The count of carachters printed.
 */
int c_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	char c;

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return (con);

	c = va_arg(args, int);

	_putchar(c);


	return (con + 1);
}

/**
 * r_specprint - will print a variable of type string in reverse
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 * Return: The count of carachters printed.
 */

int r_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	char *s, *c;
	int l;

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return (con);

	s = va_arg(args, char *);
	if (s == NULL)
		return (con);
	c = _strdup(s);
	l = _strlen(c);

	rev_string(c);
	write(1, c, l);

	free(c);
	return (con + l);
}

/**
 * R_specprint - will print a
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
  * Return: The count of carachters printed.
 */
int R_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	char *s, *c;
	int l;

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return (con);

	s = va_arg(args, char *);
	if (s == NULL)
		return (con);
	c = _strdup(s);
	l = _strlen(c);

	c = rot13(c);
	write(1, c, l);

	free(c);
	return (con + l);
}
