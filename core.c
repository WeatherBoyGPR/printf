#include "holberton.h"

/**
 * core_logic - will print a format string and connect specifiers to functions
 * @format: string to print
 * @ref: structure to pull function pointers from
 * @tal: structure to pull information from
 * @box: va list to pull variables from
 *
 * Return: total number of characters printed
 */
int core_logic(const char *format, printf_t *ref, talley_t **tal, va_list box)
{
	int index = 0, y = 1, flag = 0;
	int buf_w = 0, buf_l = 0, buf_pri = 0;
	int cnt = 0, tot = 0;

	tot = tal[0]->pri;

	while (format[index] != '\0')
	{
		flag = 0;
		if (ref != NULL && box != NULL)
			flag++;
		if (tot && tal[y]->idx == index && flag && format[index + 1] != '\0')
		{
			buf_w = tal[y]->wid;
			buf_l = tal[y]->lensym;
			buf_pri = tal[y]->pri;
			cnt = (ref[tal[y]->spec].print)(box, buf_w, buf_pri, buf_l, cnt);
			index += tal[y]->len;
			tot -= 1, y++;
		}
		else if (format[index] != '\0')
		{
			_putchar(format[index]);
			index++, cnt++;
		}
	}

	return (cnt);
}
