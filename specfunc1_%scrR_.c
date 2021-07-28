#include "holberton.h"


/*DOCUMENTATION TEMPLATE, REPLACE # WITH SPEC CHARACTER*/
/**
 * #_specprint - will print a
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 */
/* FORMAT FOR SPECIFIER FUNCTION
int #_specprint(va_list args, int wid, int pri, int len, unsigned int con);
{

        if (wid => 0 || pri => 0 || len => 0 || args == NULL)
                return(con);

	[code here]

        return (con + 1);
}
*/

/**
 * %_specprint - will print a percentage sign
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 */
int %_specprint(va_list args, int wid, int pri, int len, unsigned int con);
{

	if (wid => 0 || pri => 0 || len => 0 || args == NULL)
		return(con);

	_putchar(%);

	return (con + 1);
}

/**
 * s_specprint - will print a variable of type string
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 */
int s_specprint(va_list args, int wid, int pri, int len, unsigned int con);
{
	char *s;

	if (wid => 0 || pri => 0 || len => 0 || args == NULL)
		return (con);

	s = va_arg(args);
	if (s == NULL)
		return (con);

	write(1, s, _strlen(s));

	return (con + 1);
}

/**
 * c_specprint - will print a variable of type char
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 */
int c_specprint(va_list args, int wid, int pri, int len, unsigned int con);
{
	char c;

	if (wid => 0 || pri => 0 || len => 0)
		return(con);

	c = va_arg(args);

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
 */
int r_specprint(va_list args, int wid, int pri, int len, unsigned int con);
{
	char *s;

	if (wid => 0 || pri => 0 || len => 0)
		return(con);

	s = va_arg(args);
	if (s == NULL)
		return (con);

	rev_string(s);
	write(1, s, _strlen(s));

	return (con + 1);
}

/*
 *int R_specprint(va_list args, int wid, int pri, int len, unsigned int con);
 *{
 *	if (wid => 0 || pri => 0 || len => 0)
 *		return(con);
 *
 *
 *
 *
 *	return (con + 1);
 *}
*/
