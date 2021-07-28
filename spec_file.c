#include "holberton.h"

/**
 *
 */

void core_logic(const char *format, printf_t *ref, talley_t **tal, va_list box)
{
	int index = 0, y = 1;
	int buf_w = 0, buf_l = 0, buf_pri = 0,;
	int cnt = 0;
	
	while (format[index]!= '\0')
	{
		if (tal[0]->pri && tal[y]->idx == index)
		{
			buf_w = tal[y]->wid;
			buf_l = tal[y]->lensym;
			buf_pri = tal[y]->pri;
			cnt = (ref[tal[y]->spec]->print)(va_list box, buf_w, buf_pri, buf_l, cnt);
			index += tal[y]->len;
		}
		else if (format[index] != '\0')
		{
			putchar(format[index]);
			index++;
		}
	}
}

/**
 * _printf - Will perform formatted printing with any number of arguments
 * @format: format string to use for printing+
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
