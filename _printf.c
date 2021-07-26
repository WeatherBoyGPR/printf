#include "holberton.h"

int main()
{
	_printf("apples__%d_apples");

	return (0);
}

/*TAKE CARE OF LENGTH, WIDTH, SPEC PROBLEM COMBINATION*/
/*TAKE CARE OF WIDTH, SPEC PROBLEM COMBONATION*/

/*
   TESTS FOR INPUT VALIDATION

   +|L|W|P|S
   S|O|O|O|O
   S|X|O|O|O
   S|X|X|O|O
   S|X|X|X|O
   S|X|X|X|X
   S|X|X|O|X
   S|X|O|X|O
   S|X|O|X|X
   S|X|O|O|X
   S|O|X|O|O
   S|O|X|X|O
   S|O|X|X|X
   S|O|X|O|X
   S|O|O|X|O
   S|O|O|X|X
   |O|O|O|X
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
	/*input val*/
	tal = formatval(format, specs, tal);
	/*va_start(box, format);*/
	/* */
	/*va_end(box);*/

	printf("total elements = %d\n", tal->pri);

	printf("spec for last element = %d\n", (tal[(tal->pri)]).spec);
	free (tal);
	return (0);
}

talley_t *formatval(const char *format, printf_t *ref, talley_t *tal)
{
        int i = 0, f = 0, lbuf = -1, specbuf = 0, x, y;
        char *symlen = "hlL";
        const char *wbuf, *pbuf;

        while (*(format + i) != '\0')
        {
                x = 1, f = 0;
                if (*(format + i) == '%')
                {
                printf("START\n");
                        wbuf = NULL, pbuf = NULL, lbuf = -1, specbuf = 0;
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
                        for (y = 0; y < tal->wid && *(format + i + x) != *(ref[y].sym); y++)
                                continue;
                        if (y < tal->wid)
                                specbuf = y, f++;
                        if (f)
                                tal = talal(tal, wbuf, pbuf, lbuf, i, (x + 1), specbuf), i++;
                        printf("END\n\n");/**/
                }
                if (!f)
                        i++;
        }
        return (tal);
}


talley_t *talal(talley_t *tal[], const char *w, const char *p, int ls, int i, int l, int s)
{
	printf("_width = %s_\n_precision = %s_\n_length sym = %d_\n_index = %d_\n_speclength = %d_\n_spec num = %d_\n", w, p, ls, i, l, s);
	tal = _realloc(tal, (sizeof(talley_t *) * (1 + (tal[0].pri))), (sizeof(talley_t *) * (2 + tal[0].pri)));
	printf("TESTAAA\n");
	tal[tal[0].pri] = malloc(sizeof(talley_t));
	tal[i].lensym = ls;
	tal[i].idx = i;
	tal[i].len = l;
	tal[i].spec = s;
	if (w != NULL)
		tal[i].wid = natoi(w);
	else
		tal[i].wid = -1;
	if (p != NULL)
		tal[i].pri = natoi(p);
	else
		tal[i].pri = -1;

	tal[0].pri += 1;

	return (tal);
}

/**
 * _realloc - will reallocate space in memory
 * @ptr: memory to be reallocated
 * @old_size: size in bytes of original memory
 * @new_size: size in bytes to be allocated
 *
 * Return: pointer to allocated space on success, NULL on failure,
 * ptr on no change
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *res;
	char *accessin, *accessout;
	unsigned int i;

	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	res = malloc(new_size);
	if (!res)
		return (NULL);
	accessin = ptr;
	accessout = res;

	if (ptr)
	{
		for (i = 0; i < old_size && i < new_size; i++)
			*(accessout + i) = *(accessin + i);

		free(ptr);
	}

	return (res);
}

int natoi(const char *num)
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
