#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - function that produces output according to format
 * @format: the specified format
 * Return: returns 1 or 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int counter = 0;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			/*checks for the special case '%%'*/
			if (format[i] == '%')
			{
				putchar('%');
				counter++;
			}
			/*get appropriate function based on the specifier*/
			else
			{
				print_func func = get_function(format[i]);

				if (func != NULL)
				{
					/*call the corresponding helper function*/
					func(args, &counter);
				}
				else
				{
					/*handle invalid specifier*/
					putchar('%');
					putchar(format[i]);
					counter += 2;
				}
			}
		}
		else
		{
			/*prints regular character*/
			putchar(format[i]);
			counter++;
		}
	}
	va_end(args);
	return (counter);
}
