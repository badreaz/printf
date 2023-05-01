#include "main.h"

/**
 * get_flag - check if the char is a flag.
 * @c: character.
 *
 * Return: flag, otherwise NULL.
 */
char get_flag(char c)
{
    switch (c)
    {
        case '+':
            break;
        case ' ':
            break;
        case '#':
            break;
        default:
            return (NULL);
    }
    return (c);
}

/**
 * add_flag - edit the string according to the flag.
 * @num: number in string form.
 * @arg: struct that handle flag.
 *
 * Return: pointer to string.
 */
char *add_flag(char *num, arg_t arg)
{
    char *newstr;

    switch (arg.flag)
    {
        case '+':
            if (num[0] != '-')
            {
                newstr[0] = '+';
                strcat(newstr, num);
            }
            break;
        case ' ':
            if (num[0] != '-')
            {
                newstr[0] = ' ';
                strcat(newstr, num);
            }
            break;
        case '#':
            if (arg.type == 'o')
            {
                newstr[0] = '0';
                strcat(newstr, num);
            }
            else if (arg.type == 'x')
            {
                newstr = "0x";
                strcat(newstr, num);
            }
            break;
        default:
            return (NULL);
    }
    newstr = strdup(newstr);
    free(num);
    return (newstr);
}