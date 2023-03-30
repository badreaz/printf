#include "main.h"

/**
 * p_type - convert pointer to char * in hexadecimal.
 * @p: pointer.
 *
 * Return: pointer to string.
 */
char *p_type(va_list p)
{
	char *s, *ptr;
	int i, j;

	ptr = va_arg(p, char *);
	/* add code */
	s = malloc(_strlen(ptr) + 3);
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	s[0] = '0';
        s[1] = 'x';
	i = 2;
	j = 0;
	while (ptr[j])
	{
		s[i] = ptr[j];
		i++;
		j++;
	}
	s[i] = '\0';
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
