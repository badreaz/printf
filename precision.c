#include "main.h"

/**
 * get_precision - check if the char is a precision.
 * @c: character.
 * @mark: the precision mark.
 *
 * Return: precision, otherwise NULL.
 */
char get_precision(char c, char mark)
{
    if (mark == '.')
    {
        if ('0' <= c && c <= '9')
        {
            return (c);
        }
    }
    return (NULL);
}

/**
 * add_precision - fill blanks.
 * @str: string.
 * @arg: struct to precision.
 *
 * Return: pointer to str.
 */
char *add_precision(char *str, arg_t arg)
{
    char *newstr;
    int i, len;

    len = _strlen(str);
    if (arg.type == 's' && len > arg.precision)
        str[arg.precision] = '\0';
    else if (len < arg.precision)
    {
        for (i = arg.precision - len; i; i--)
            strcat(newstr, "0");
        newstr = _strdup(newstr);
        free(str);
        return (newstr);
    }
    return (str);
}