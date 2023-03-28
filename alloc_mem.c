#include "main.h"

/**
 * alloc_mem - allocate memory to string.
 * @buffer: bufffer to allocate memory to.
 * @ans: string to add to buffer.
 * @index: the index of buffer.
 * @count: word count of whole buffer.
 *
 * Return: the word count of whole buffer.
 */
int alloc_mem(char *buffer[], char *ans, int index, int count)
{
	int len = _strlen(ans);

	buffer[index] = malloc(sizeof(ans));
	_memcpy(buffer[index], ans, len + 1);
	count += len;
	return (count);
}
