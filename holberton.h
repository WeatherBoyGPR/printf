#ifndef LOVETRAIN
#define LOVETRAIN

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct printf_ - Ties together specification chars and function pointers
 * @sym: string beginning with specification char
 * @print: function pointer to appropriate function
 */
typedef struct printf_
{
	char *sym;
	int (*print)(va_list arg, int wid, int pri, int len, unsigned int con);
} printf_t;

/**
 * struct talley - is meant to hold information regarding each found specifier
 * @wid: width specifier. -1 if not found
 * @pri: precision specifier, -1 if not found
 * @lensym: index of length specifier in length string, -1 if not found
 * @idx: index of specifier in format string
 * @len: length of specifier in format string
 * @spec: index of specifier character in printf_ structure array
 */
typedef struct talley
{
	int wid;
	int pri;
	int lensym;
	int idx;
	int len;
	int spec;
} talley_t;

typedef const char cch;

/*store total number of functions in talley[0].wid*/
/*store total number of found specifiers in talley[0].pri*/

int _printf(const char *format, ...);
talley_t **formatval(const char *format, printf_t *ref, talley_t **tal);
talley_t **talal(talley_t **tal, cch *w, cch *p, int ls, int i, int l, int s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freetally(talley_t **tal);
int natoi(cch *num);
void printtally(talley_t **tal);

#endif
