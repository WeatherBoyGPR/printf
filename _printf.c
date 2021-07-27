#include "holberton.h"

int main(void)
{
	_printf("apple%1231.123s_%L123.41apples%s, %23s");

	return (0);
}

/*
 *  TESTS FOR INPUT VALIDATION
 *  +|L|W|P|S
 *  S|O|O|O|O
 *  S|X|O|O|O
 *  S|X|X|O|O
 *  S|X|X|X|O
 *  S|X|X|X|X
 *  S|X|X|O|X
 *  S|X|O|X|O
 *  S|X|O|X|X
 *  S|X|O|O|X
 *  S|O|X|O|O
 *  S|O|X|X|O
 *  S|O|X|X|X
 *  S|O|X|O|X
 *  S|O|O|X|O
 *  S|O|O|X|X
 *  S|O|O|O|X
 */

int _printf(const char *format)
{
	/*va_list box;*/
	talley_t **tal;

	/*struct array printf*/
	printf_t specs[] = {
		{"d", NULL},
		{"s", NULL},
		{"a", NULL},
	};

	tal = malloc(sizeof(talley_t *));

	tal[0] = malloc(sizeof(talley_t));
	if (tal == NULL)
		return (1);

	tal[0]->wid = 3;
	tal[0]->pri = 0;
	/*input val*/
	tal = formatval(format, specs, tal);
	/*va_start(box, format);*/
	/* */
	/*va_end(box);*/

	printtally(tal);
	freetally(tal);
	return (0);
}

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
			printf("START\n");
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
			printf("y = %d\ncomp = %d\n", y, tal[0]->wid);
			if (y < tal[0]->wid)
				specbuf = y, f++;
			printf("f = %d\n", f);
			if (f)
				tal = talal(tal, wbuf, pbuf, lbuf, i, (x + 1), specbuf), i++;
			printf("END\n\n");
		}
		if (!f)
			i++;
	}
	return (tal);
}


talley_t **talal(talley_t **tal, cch *w, cch *p, int ls, int i, int l, int s)
{
	int idx, sot;

	sot = (sizeof(talley_t *));

	idx = (tal[0]->pri + 1);
	tal = _realloc(tal, (sot) * (1 + (tal[0]->pri)), (sot) * (2 + tal[0]->pri));
	printf("TESTAAA\n");
	tal[tal[0]->pri + 1] = malloc(sizeof(talley_t));
	printf("TESTBBB\n");
	tal[idx]->lensym = ls;
	tal[idx]->idx = i;
	tal[idx]->len = l;
	tal[idx]->spec = s;
	printf("TESTCCC\n");
	if (w != NULL)
		tal[idx]->wid = natoi(w);
	else
		tal[idx]->wid = -1;
	if (p != NULL)
		tal[idx]->pri = natoi(p);
	else
		tal[idx]->pri = -1;
	tal[0]->pri += 1;
	printf("TESTZZZ\n");
	return (tal);
}

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
