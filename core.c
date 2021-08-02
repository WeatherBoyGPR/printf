#include "holberton.h"

/**
 *
 */
int core_logic(const char *format, printf_t *ref, talley_t **tal, va_list box)
{
	int index = 0, y = 1;/*, tem = 0;*/
	int buf_w = 0, buf_l = 0, buf_pri = 0;
	int cnt = 0;

	printf("CORELOGIC_START\n");
	while (format[index]!= '\0')
	{
		/*printf("TEST1");*/
		if (tal[0]->pri && tal[y]->idx == index && ref != NULL && box != NULL)
		{
			buf_w = tal[y]->wid;
			buf_l = tal[y]->lensym;
			buf_pri = tal[y]->pri;
			/*tem = index;*/
			/*printf("TEST2");*/
			cnt = (ref[tal[y]->spec].print)(box, buf_w, buf_pri, buf_l, cnt);
			index += tal[y]->len;
			tal[0]->pri -= 1;
		}
		else if (format[index] != '\0')
		{
			/*printf("TEST3");*/
			/*tem = index;*/
			putchar(format[index]);
			index++;
		}
		/*printf(" - INDEX = %d", tem);*/
	}

	printf("CORELOGIC_END\n");
	return (cnt);
}