#include "main.h"

/**
 * find_type - print conversion specifier.
 * @c: conversion specifier.
 *
 * Return: pointer to type function, otherwise NULL.
 */
char *(*find_type(char c))(va_list)
{
	type_t types[] = {
		{'c', c_type},
		{'s', s_type},
		{'%', m_type},
		{'d', i_type},
		{'i', i_type},
		{'b', b_type},
		{'u', u_type},
		{'o', o_type},
		{'x', x_type},
		{'X', X_type},
		{'S', S_type},
		{'p', p_type},
		{'r', r_type},
		{'R', R_type}
	};
	int i;

	for (i = 0; i < 14; i++)
	{
		if (c == types[i].specifier)
			return(types[i].f);
	}
	return (NULL);
}
