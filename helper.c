#include "main.h"

/**
 * itohex - convert int to hexadecimal.
 * @n: int value of char.
 *
 * Return: pointer to hexadecimal value.
 */
char *itohex(int n)
{
	int i = 0, j, div = 1;
	char *s;

	s = malloc(3 * sizeof(char));
	j = n;
	while (j / 16)
	{
		div *= 16;
		j /= 16;
	}
	if (n < 16)
	{
		s[i] = '0';
		i++;
	}
	while (div != 0)
	{
		if (n / div < 10)
			s[i] = ((n / div) % 16) + '0';
		else
			s[i] = ((n / div) % 16) + 87;
		div /= 16;
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * _memcpy - copies memory area.
 * @dest: pointer to copy to.
 * @src: pointer to copy from.
 * @n: number of byte.
 * @index: buffer index to empty memory.
 */
void _memcpy(char *dest, char *src, unsigned int n, unsigned int index)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i + index] = src[i];
		i++;
	}
}

/**
 * _strlen - return the length of a string.
 * @s: pointer to char.
 *
 * Return: the length of string.
 */
int _strlen(char *s)
{
	char *p = s;
	int count = 0;

	while (*p != '\0')
	{
		count++;
		p++;
	}
	return (count);
}

/**
 * ctos - convert character to char *.
 * @c: character.
 *
 * Return: pointer to string.
 */
char *ctos(char c)
{
	char *s;

	s = malloc(2);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

/**
 * mtos - convert character to char *.
 * @c: character.
 *
 * Return: pointer to string.
 */
char *mtos(char c)
{
        char *s;

        s = malloc(3 * sizeof(char));
	if (s == NULL)
		return (0);
	s[0] = '%';
        s[1] = c;
        s[2] = '\0';
        return (s);
}

/**
 * _strdup - copy a string to allocated memory.
 * @str: pointer to string.
 *
 * Return: the pointer to allocated memory, otherwise NULL.
 */
char *_strdup(char *str)
{
	char *p;
	int size = 0;

	if (str == 0)
		return (0);
	while (str[size] != '\0')
		size++;
	size++;
	p = malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	size = 0;
	while (str[size] != '\0')
	{
		p[size] = str[size];
		size++;
	}
	p[size] = '\0';
	return (p);
}
