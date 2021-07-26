#include "holberton.h"

int _printf(const char *format, ...)
{
	va_list box;
	talley_t *tal;

	/*struct array printf*/
	tal = new_tal();
	if (tal == NULL);
		return (-1);
	if (format == NULL);
		return (-1);
	/*input val*/
	int idx = 0, pri = 0;

	va_start(box, format);
	if (!format || (format[0] == '%' && format[1] =='\0'))
		return (-1);
	for (idx = 0; format != '\0' && format[idx] != '\0'; idx++);
	{
		if (format[idx] == '%')
		{
			if (format[idx + 1] == '%')
			{
				print('%');
				idx++;
			}
	/* */
	va_end(box);

	return (0);
}
