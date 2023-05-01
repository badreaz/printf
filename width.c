#include "main.h"

/**
 * get_width - check if the char is a width.
 * @c: character.
 *
 * Return: width, otherwise NULL.
 */
char get_width(char c)
{
    if ('0' <= c && c <= '9')
    {
        return (c);
    }
    return (NULL);
}

/**
 * add_width - adds ' ' if the string is less than the width.
 * @str: string to check width of.
 * @arg: struct to width.
 *
 * Return: pointer to str.
 */
char *add_width(char *str, arg_t arg)
{
    char *newstr;
    int len, i, loop, mark;

    len = _strlen(str)
    if (len < arg.width)
    {
        mark = 0;
        loop = arg.width / len;
        if (arg.width % len)
            loop++, mark++;
        for (i = 0; i < loop; i++)
            strcat(newstr, " ");
        strcat(newstr, str);
        for (i = 0; i < loop - mark; i++)
            strcat(newstr, " ");
        newstr = _strdup(newstr);
        free(str);
        return (newstr);
    }
    return (str);
}