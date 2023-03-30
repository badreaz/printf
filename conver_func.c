#include "main.h"

/**
 * c_type - convert char to char *.
 * @c: char to convert.
 *
 * Return: pointer to string.
 */
char *c_type(va_list c)
{
	char *s;

	s = malloc(2 * sizeof(char));
	if (s)
	{
		s[0] = va_arg(c, int);
		s[1] = '\0';
	}
	else
	{
		free(s);
		return (NULL);
	}
	return (s);
}

/**
 * s_type - convert char * to char *.
 * @s: string.
 *
 * Return: pointer to string.
 */
char *s_type(va_list s)
{
	char *string;

	string = va_arg(s, char *);
	return (string);
}

/**
 * m_type - convert modular to char *.
 * @m: modular.
 *
 * Return: pointer to string.
 */
char *m_type(va_list m)
{
	char *s;

	s = va_arg(m, char *);
	return (s);
}

/**
 * i_type - convert decimals to char *.
 * @i: integer.
 *
 * Return: pointer to string.
 */
char *i_type(va_list i)
{
	char *s;
	int num, c = 0, j, div = 1;

	num = va_arg(i, int);
	if (num < 0)
	{
		j = -num;
		c++;
	}
	else
		j = num;

	while (j / 10)
	{
		div *= 10;
		j /= 10;
		c++;
	}
	s = malloc((c + 2) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	c = 0;
	if (num < 0)
	{
		s[c] = '-';
		num *= -1;
		c++;
	}
	while (div != 0)
	{
		j = num / div;
		s[c] = (j % 10) + '0';
		c++;
		div /= 10;
	}
	s[c] = '\0';
	return (s);
}

/**
 * b_type - convert unsigned int to char * in binary form.
 * @b: unsigned int.
 *
 * Return: pointer to string.
 */
char *b_type(va_list b)
{
	unsigned int num, i = 0, j, div = 1;
	char *s;

	num = va_arg(b, unsigned int);
	j = num;
	while (j / 2)
	{
		div *= 2;
		j /= 2;
		i++;
	}
	s = malloc((i + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (div > 0)
	{
		s[i] = ((num / 2) % 2) + '0';
		div /= 2;
		i++;
	}
	s[i] = '\0';
	return (s);
}
