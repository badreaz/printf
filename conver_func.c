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
	if (string == NULL)
	{
		string = "(nil)";
	}

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

/**
 * p_type - convert pointer to char * in hexadecimal.
 * @p: pointer.
 *
 * Return: pointer to string.
 */
char *p_type(va_list p)
{
	char *s;

	s = va_arg(p, char *);
	/* add code */
	return (s);
}

/**
 * r_type - reverse a string.
 * @r: pointer to string.
 *
 * Return: pointer to the reversed string.
 */
char *r_type(va_list r)
{
	char *s, *str;
	int count = 0, n = 0, i = 0;

	str = va_arg(r, char *);
	s = malloc(sizeof(str));
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	while (n < count)
	{
		i--;
		s[n] = str[i];
		n++;
	}
	s[n] = '\0';
	return (s);
}

/**
 * R_type - encodes a string using rot-13.
 * @R: pointer to string.
 *
 * Return: pointer to string.
 */
char *R_type(va_list R)
{
	char *str;
	int i, c;
	char *rot_13 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *out_13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(R, char *);
	c = 0;
	while (str[c] != '\0')
	{
		for (i = 0; i < 52; i++)
		{
			if (str[c] == rot_13[i])
			{
				str[c] = out_13[i];
				break;
			}
		}
		c++;
	}
	return (str);
}
