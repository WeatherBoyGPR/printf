#include "holberton.h"

/**
 * rev_string - will reverse a string
 * @s: the string to be reversed
 *
 * Return: doesn't
 */
void rev_string(char *s)
{
	char buf;
	int i;
	int len;

	for (len = 0; s[len] != '\0'; len++)
		continue;

	len--;

	for (i = 0; i <= len ; i++)
	{
		buf = s[len];
		s[len] = s[i];
		s[i] = buf;
		len--;
	}
}

/**
 * _strlen - will find the length of the string
 * @s: a pointer to the string
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (*s)
	{
		while (*(s + i) != '\0')
			i++;
	}

	return (i);
}

void printtally(talley_t **tal)
{
	int idx = 0, j  = tal[0]->pri;
	int w = 0, p = 0, ls = 0, i = 0, l = 0, s = 0;

	while (idx <= j)
	{
		if (idx > 0)
		{
			w = tal[idx]->wid;
			p = tal[idx]->pri;
			ls = tal[idx]->lensym;
			i = tal[idx]->idx;
			l = tal[idx]->len;
			s = tal[idx]->spec;
			printf("\nSTARTPRINT - %d\n", idx);
			printf("_width = %d_\n_precision = %d_\n_length sym = %d_\n", w, p, ls);
			printf("_index = %d_\n_speclength = %d_\n_spec num = %d_\n", i, l, s);
			printf("ENDPRINT - %d\n", idx);
		}
		else
		{
			printf("total elements = %d\n", tal[0]->pri);
			printf("spec for last element = %d\n", (tal[(tal[0]->pri)])->spec);

		}
		idx++;
	}
}

void freetally(talley_t **tal)
{
	int i = 0, j  = tal[0]->pri;

	while (i <= j)
	{
		free(tal[i]);
		i++;
	}
	free(tal);
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

