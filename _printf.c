#include "holberton.h"

/**
 * _printf - Will perform formatted printing with any number of arguments
 * @format: format string to use for printing
 *
 * Return: always 0
 */
int _printf(const char *format, ...)
{
	int num;
	va_list box;
	talley_t **tal;
	char *err = "Error : NO FORMAT STRING\n";

	printf_t specs[] = {
		{"c", c_specprint},
		{"s", s_specprint},
		{"%", mod_specprint},
		{"r", r_specprint},
		{"R", R_specprint},
		{"i", di_specprint},
		{"d", di_specprint},
		{"u", di_specprint},
		{"b", b_specprint},
		{"p", p_specprint},
	};
	if (format == NULL)
	{
		write(2, err, _strlen(err));
		return (_strlen(err));
	}
	tal = malloc(sizeof(talley_t *));
	if (tal == NULL)
		return (0);

	tal[0] = malloc(sizeof(talley_t));
	if (tal[0] == NULL)
		return (0);
	tal[0]->wid = 10;
	tal[0]->pri = 0;
	tal = formatval(format, specs, tal);
	va_start(box, format);
	num = core_logic(format, specs, tal, box);
	freetally(tal);

	va_end(box);
	return (num);
}



/**
 * formatval - will validate a format string and fill a structure array
 * @format: format string to validate
 * @ref: structure which contains specifiers and function their pointers
 * @tal: talley_t structure array information is to be stored in
 *
 * Return: a pointer to the completed array
 */
talley_t **formatval(const char *format, printf_t *ref, talley_t **tal)
{
	int i = 0, f = 0, lbuf = -1, specbuf = 0, x, y;
	char *symlen = "hlL";
	cch *wbuf, *pbuf;

	while (*(format + i) != '\0')
	{
		x = 1, f = 0;
		if (*(format + i) == '%')
		{
			wbuf = NULL, pbuf = NULL, lbuf = -1, specbuf = 0, x = 1, f = 0;
			/*Checks for length modifier*/
			for (y = 0; symlen[y] != '\0' && *(format + i + x) != symlen[y]; y++)
				continue;
			if (symlen[y] != '\0')
				lbuf = y, x++;
			for (y = 0; format[i + x + y] <= '9' && format[i + x + y] >= '0'; y++)
				if (!y)
					wbuf = (format + i + x + y);
			x += y;
			if (*(format + i + x) == '.')
				for (y = 1; (format[i + x + y] <= '9' && format[i + x + y] >= '0'); y++)
					if (y == 1)
						pbuf = (format + i + x + 1), f++;
			if (f)
				x += y, f = 0;
			for (y = 0; y < tal[0]->wid && *(format + i + x) != *(ref[y].sym); y++)
				continue;
			if (y < tal[0]->wid)
				specbuf = y, f++;
			if (f)
				tal = talal(tal, wbuf, pbuf, lbuf, i, (x + 1), specbuf), i += (x + 1);
		}
		if (!f)
			i++;
	}
	return (tal);
}

/**
 * talal - will allocate a new element in a talley_t structure array,
 * fills element with information about valid specifier
 * @tal: talley_t structure array to add to
 * @w: pointer to where the width begins in the format string
 * @p: pointer to where the precision begins in the format string
 * @ls: index of length specifier
 * @i: index of conversion specifier in format string
 * @l: length of conversion specifier in format string
 * @s: index of specifier character in printf_t structure array
 *
 * Return: pointer to talley_t structure array
 */
talley_t **talal(talley_t **tal, cch *w, cch *p, int ls, int i, int l, int s)
{
	int idx, sot;

	sot = (sizeof(talley_t *));

	idx = (tal[0]->pri + 1);
	tal = _realloc(tal, (sot) * (1 + (tal[0]->pri)), (sot) * (2 + tal[0]->pri));
	tal[tal[0]->pri + 1] = malloc(sizeof(talley_t));
	tal[idx]->lensym = ls;
	tal[idx]->idx = i;
	tal[idx]->len = l;
	tal[idx]->spec = s;
	if (w != NULL)
		tal[idx]->wid = natoi(w);
	else
		tal[idx]->wid = -1;
	if (p != NULL)
		tal[idx]->pri = natoi(p);
	else
		tal[idx]->pri = -1;
	tal[0]->pri += 1;
	return (tal);
}

/**
 * natoi - will atoi all beginning numerical characters in a string
 * @num: string to process
 *
 * Return: resulting number
 */
int natoi(cch *num)
{
	int i = 0;
	char *res;

	if (num == NULL)
		return (-1);

	while (*(num + i) >= '0' && *(num + i) <= '9')
		i++;

	res = malloc((i * sizeof(char)) + 1);
	if (res == NULL)
		return (-1);

	for (i = 0; num[i] >= '0' && num[i] <= '9'; i++)
	{
		*(res + i) = num[i];
	}

	*(res + i) = '\0';
	/*replace atoi function later*/
	i = atoi(res);

	free(res);

	return (i);
}
