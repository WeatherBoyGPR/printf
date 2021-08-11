#include "holberton.h"

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

/**
 * b_specprint - will print a unsigned integer as a binary number
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of printed characters
 */
int b_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	unsigned int b = 0, idx = 0, count = 0;
	char *str;

	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);
	str = malloc(sizeof(char) * (1 + (sizeof(unsigned int) * 8)));
	if (str == NULL)
		return(con);
	b = va_arg(args, unsigned int);
	do {
		str[idx] = ((b & 1) + '0');
		b = b >> 1;
		idx++;
	} while (b != 0);
	str[idx] = '\0';

	rev_string(str);
	for (idx = 0; str[idx] != '\0'; idx++)
	{
		_putchar(str[idx]);
		count++;
	}
	free(str);
	return (con + count);
}
