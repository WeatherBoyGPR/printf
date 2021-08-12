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

/**
 * p_specprint - will print a pointer
 * @args: va_list to obtain variable from
 * @wid: width modifier to print variable with, -1 if unused
 * @pri: precision modifier to print variable with, -1 if unused
 * @len: length modifier to print variable with, -1 if unused
 * @con: variable to keep track of number of specifier functions
 */
int p_specprint(va_list args, int wid, int pri, int len, unsigned int con)
{
	void *add;
	char *com[] = {":;<=>?", "abcdef"}, *str = NULL, *alt = NULL;
	unsigned int idx = 0, count = 0, y = 0;
	unsigned long int point;
	if (!(wid == -1 && pri == -1 && len == -1 && args != NULL))
		return(con);
	str = malloc(((sizeof(void *) * 8) + 1) * sizeof(char));
	if (str == NULL)
		return(con);
	alt = str;
	add = va_arg(args, void *);
	point = (unsigned long int)add;
	if (point)
	{
		do {
			str[idx] = ((point & 15) + '0');
			point = point >> 4;
			idx++;
		} while (point != 0);
		str[idx] = '\0';
		for (idx = 0; str[idx] != '\0'; idx++)
			for (y = 0; *(com[0] + y) != '\0'; y++)
				if (str[idx] == *(com[0] + y))
				{
					str[idx] = *(com[1] + y);
					break;
				}
		rev_string(str);
		_putchar('0');
		_putchar('x');
		count += 2;
	}
	else
		str = "(nil)";
	for (idx = 0; str[idx] != '\0'; idx++)
	{
		_putchar(str[idx]);
		count++;
	}
	free(alt);
	return (con + count);
}
