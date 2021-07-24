#ifndef LOVETRAIN
#define LOVETRAIN

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct printf_
{
        char *sym;
        int (*print)(va_list arg, int w, int p, int c);
} printf_t;

#endif
