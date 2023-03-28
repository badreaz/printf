#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format.
 * @format: format of the parameters.
 *
 * Return: the numbers of characters printed.
 */
int _printf(const char *format, ...)
{
	int c = 0, i, j, x;
	va_list list;
	char *ans, *string[1024];

	va_start(list, format);
	i = 0;
	j = 0;
	while (format != 0 && format[i])
	{
		if (format[i] == '%')
		{
			if (find_type(format[i]) == NULL)
				ans = ctos(format[i]);
			else
				ans = find_type(format[i])(list);
			c = alloc_mem(string, ans, j, c);
		}
		else
		{
			ans = ctos(format[i]);
			c = alloc_mem(string, ans, j, c);
		}
		i++;
		j++;
	}
	va_end(list);
	/* print string */
	for (i = 0; i < j; i++)
	{
		for (x = 0; string[i]; i++)
			write(1, &string[i][x], 1);
	}
	return (c);
}
