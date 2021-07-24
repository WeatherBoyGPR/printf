#ifndef LOVETRAIN
#define LOVETRAIN

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct printf_
{
        char *sym;
        int (*print)(va_list arg, int wid, int pri, int len, unsigned int con);
} printf_t;

#endif
