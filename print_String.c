#include "main.h"

/**
 * print_String - print exclusuives string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int print_String(va_list l)
{
	register short len = 0;
	char *res, *s = va_arg(l, char *);
	int count;

	if (!s)
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if (isNonAlphaNumeric(*s))
		{
			count += _puts("\\x");
			res = convert(*s, 16, 0);
			if (!res[1])
				len += _putchar('0');
			len += _puts(res);
		}
		else
			len += _putchar(*s);
	}
	return (len);
}

int isNonAlphaNumeric(char c) 
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = NUL;
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);

	return (ptr);
}
