#include "holberton.h"
/*
int functtest(int n, ...)
{
	va_list args;
	va_start(args, n);

	n = mod_specprint(args, -1, -1, -1, 0);
	n = s_specprint(args, -1, -1, -1, n);
	va_end(args);
	return (n);
}

int main(void)
{
	functtest(1);
	return (0);
}
*/

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

        if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
                return(con);

	[code here]

        return (con + 1);
}
*/

/**
 * mod_specprint - will print a percentage sign
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 */
int mod_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);

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
		printf("%sWCWCWCWC", err);
		return (con);
	}

	printf("TEST SPEC PRINT S");
	/*write(1, s, _strlen(s));*/

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
int c_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	char c;

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);

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
 */
int r_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	char *s;

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);

	s = va_arg(args, char *);
	if (s == NULL)
		return (con);

	rev_string(s);
	write(1, s, _strlen(s));

	return (con + 1);
}

/**
 * #_specprint - will print a
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 */
int R_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	char *s;

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return (con);

	s = va_arg(args, char *);
	if (s == NULL)
		return (con);

	s = rot13(s);
	write(1, s, _strlen(s));
	return (con + 1);
}
