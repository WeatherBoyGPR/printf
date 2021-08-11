#include "holberton.h"

/**
 * di_specprint - will print an integer
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of characters printed
 */
int di_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	long int num = 0, new = 0, n = 32;
	int idx = 0, count = 0;
	char *arr;

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);
	num = va_arg(args, int);
	arr = malloc(sizeof(char) * n);
	if (arr == NULL)
		return (con);
	if (num < 0)
	{
		_putchar('-');
		count++;
		new = num *(-1);
	}
	else
		new = num;
	do {
		arr[idx] = ((new % 10) + '0');
		new = (new / 10);
		idx++;
	} while (new != 0);

	arr[idx] = '\0';
	rev_string(arr);
	for (idx = 0; arr[idx] != '\0'; idx++)
	{
		_putchar(arr[idx]);
		count++;
	}
	free(arr);
	return (con + count);
}
