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
	while (div > 1)
	{
		if (n / div < 10)
			s[i] = ((n / div) % 16) + '0';
		else
			s[i] = ((n / div) % 16) + 'a';
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
 */
void _memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		*dest = *src;
		dest++;
		src++;
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
