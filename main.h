#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * struct type - Struct type
 *
 * @specifier: The operator
 * @f: The function associated
 */
typedef struct type
{
	char specifier;
	char *(*f)(va_list);
} type_t;
int _printf(const char *format, ...);
char *(*find_type(char s))(va_list);
char *c_type(va_list c);
char *s_type(va_list s);
char *m_type(va_list m);
char *i_type(va_list i);
char *b_type(va_list b);
char *u_type(va_list u);
char *o_type(va_list o);
char *x_type(va_list x);
char *X_type(va_list X);
char *S_type(va_list S);
char *p_type(va_list p);
char *r_type(va_list r);
char *R_type(va_list R);
void _memcpy(char *, char *, unsigned int, unsigned int);
char *itohex(int n);
int _strlen(char *s);
char *ctos(char c);
int alloc_mem(char *buffer, char *ans, int index, int count);

#endif
