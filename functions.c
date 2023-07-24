#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_char - function that prints characters
 * @counter: pointer to counter
 * @args: arguments
 * Return: Returns nothing
 */
void print_char(va_list args, int *counter)
{
	char ch = va_arg(args, int);

	putchar(ch);
	(*counter)++;
}
/**
 * print_string - function that prints string
 * @counter: pointer to a counter
 * @args: arguments
 * Return: Returns nothing
 */
void  print_string(va_list args, int *counter)
{
	char *str = va_arg(args, char *);
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
		(*counter)++;
	}
}
/**
 * print_integer - function that prints integer
 * @counter: pointer to a counter
 * @args: arguments
 * Return: returns nothing
 */
void print_integer(va_list args, int *counter)
{
	int num = va_arg(args, int);
	int digits = 1;

	if (num < 0)
	{
		putchar('-');
		(*counter)++;
		num = -num;
	}

	while (num / digits > 9)
		digits *= 10;

	while (digits)
	{
		putchar('0' + num / digits);
		(*counter)++;
		num %= digits;
		digits /= 10;
	}
}
