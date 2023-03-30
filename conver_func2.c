#include "main.h"

/**
 * u_type - convert unsigned int to char *.
 * @u: unsigned int.
 *
 * Return: pointer to string.
 */
char *u_type(va_list u)
{
	unsigned int num, i = 0, j = 0, div = 1;
	char *s;

	num = va_arg(u, unsigned int);
	j = num;
	while (j / 10)
	{
		div *= 10;
		j /= 10;
		i++;
	}
	s = malloc((i + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (div != 0)
	{
		s[i] = ((num / div) % 10) + '0';
		div /= 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * o_type - convert unsigned int to char * in octal.
 * @o: unsigned int.
 *
 * Return: pointer to string.
 */
char *o_type(va_list o)
{
	char *s;
	unsigned int num, i = 0, j, div = 1;

	num = va_arg(o, unsigned int);
	j = num;
	while (j / 8)
	{
		div *= 8;
		j /= 8;
		i++;
	}
	s = malloc((i + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (div != 0)
	{
		j = num / div;
		s[i] = (j % 8) + '0';
		div /= 8;
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * x_type - convert unsigned int to char * in hexadecimal form.
 * @x: unsigned int.
 *
 * Return: pointer to string.
 */
char *x_type(va_list x)
{
	char *s;
	unsigned int num, i = 0, j, div = 1;

	num = va_arg(x, unsigned int);
	j = num;
	while (j / 16)
	{
		div *= 16;
		j /= 16;
		i++;
	}
	s = malloc((i + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (div != 0)
	{
		j = (num / div) % 16;
		if (j < 10)
			s[i] = j + '0';
		else
			s[i] = j + 'a';
		div /= 16;
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * X_type - convert unsigned int to char * in hexadecimal form.
 * @X: unsigned int.
 *
 * Return: pointer to string.
 */
char *X_type(va_list X)
{
	char *s;
	unsigned int num, i = 0, j, div = 1;


	num = va_arg(X, unsigned int);
	j = num;
	while (j / 16)
	{
		div *= 16;
		j /= 16;
		i++;
	}
	s = malloc((i + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (div != 0)
	{
		j = (num / div) % 16;
		if (j < 10)
			s[i] = j + '0';
		else
			s[i] = j + 'A';
		div /= 16;
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * S_type - convert string to char *.
 *  - converts non-printable charaters to '\x' followed
 *  by their hexadecimal.
 * @S: string.
 *
 * Return: pointer to string.
 */
char *S_type(va_list S)
{
	char *s, *str, *hex;
	int i, j, x;


	str = va_arg(S, char *);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32)
			i += 3;
	}
	s = malloc((i + 1) * sizeof(char));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	for (i = 0, j = 0; str[i]; i++, j++)
	{
		if (str[i] < 32)
		{
			s[j] = '\\';
			s[j++] = 'x';
			hex = itohex(str[i]);
			for (x = 0; x < 3; x++)
				s[j++] = hex[x];
		}
		else
			s[j] = str[i];
	}
	s[j] = '\0';
	return (s);
}
