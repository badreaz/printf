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
int alloc_mem(char *buffer, char *ans, int index, int count)
{
	int len = _strlen(ans);

	_memcpy(buffer, ans, len + 1, index);
	count += len;
	return (count);
}

/**
 * init_buf - initialize the buffer.
 * @buffer: pointer to array.
 */
void init_buf(char *buffer)
{
	int i;

	for (i = 0; i < 1024; i++)
		buffer[i] = 0;
}
