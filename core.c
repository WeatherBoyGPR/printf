#include "holberton.h"

/**
 *
 */
int core_logic(const char *format, printf_t *ref, talley_t **tal, va_list box)
{
	int index = 0, y = 1;/*, tem = 0;*/
	int buf_w = 0, buf_l = 0, buf_pri = 0;
	int cnt = 0, tot = 0;

	tot = tal[0]->pri;

	while (format[index]!= '\0')
	{
		/*printf("TEST1");*/
		if (tot != 0 && tal[y]->idx == index && ref != NULL && box != NULL)
		{
			buf_w = tal[y]->wid;
			buf_l = tal[y]->lensym;
			buf_pri = tal[y]->pri;
			/*tem = index;*/
			cnt = (ref[tal[y]->spec].print)(box, buf_w, buf_pri, buf_l, cnt);
			index += tal[y]->len;
			tot -= 1, y++;
		}
		else if (format[index] != '\0')
		{
			/*printf("TEST3");*/
			/*tem = index;*/
			_putchar(format[index]);
			index++;
		}
		/*printf(" - INDEX = %d", tem);*/
	}

	return (cnt);
}
