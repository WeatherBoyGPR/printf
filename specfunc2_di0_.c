#include "holberton.h"
/*
 

int functtest(int n, ...)
{
	va_list args;
	va_start(args, n);
	n = nul_specprint(args, -1, -1, -1, 0);
	n = di_specprint(args, -1, -1, -1, n);
	n = i_specprint(args, -1, -1, -1, n);
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
int di_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);

	_putchar('');

	return (con + 1);
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

int i_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);

	i = va_arg(args, int);
	int num = 0;
	int arr[];
	int idx = 0;
	int count += 0;
	unsigned int new;

	if (num < 0)
	{
		count += _putchar('-');
		new = num *(-1);
	}
	else
		new = num;
	if (new == 0)
	{
		count += _putchar(new + '0');
		return (count);
	}
	while (new != 0)
	{
		arr[indx] = ((new % 10 ) + '0');
		new = (new / 10);
		idx++;
	}
	for (idx = idx - 1; idx >= 0; idx--)
	{
		count += _putchar (arr[idx] + '0');
		return (count);
	}
	return (con + 1);
}
*/
/**
 * nul_specprint - will handle a null byte specifier
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of printed characters
 */
int nul_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);

	return (con);
}
