#0x11-printf
This is the repository devoted to the holberton school low level programming _printf project.


FILES
=====
man_3_printf
	man_3_printf - Manual page for printf program

_printf.c
	_printf - will print a format string, replacing specifiers with variables
	formatval - will fill an array of structures with information about all valid specifiers
	talal - will allocate a new element in a talley_t structure array, fill new element with specifier information
	natoi - will atoi all characters in a string up until the first non numerical character

util.c
	rev_string - will reverse the contents of a string
	_strlen - will find the length of a string
	printtally - will print the contents of a structure array of talley_t
	freetally - will free a structure array of talley_t
	_realloc - will realloc space in memory, copying over what will fit in the new memory
holberton.h
	struct _printf - holds specification characters and their associated functions
	struct talley - holds information about valid conversion specifiers

AUTHORS
=======
-Johanne Lopez
-Gino Rossi Jr
