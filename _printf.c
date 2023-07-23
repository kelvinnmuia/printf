#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

/**
 * _printf - function that produces output according to format
 * @format: the specified format 
 * Return: returns 1 or 0
 */
int _printf(const char *format, ...)
{
	va_list ags;
	int i;
	int j;
	int counter = 0;
	va_start(ags, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '%')
			{
				putchar('%');
				counter++;
			}
			else if(format[i] == 'c')
			{
				char ch = va_arg(ags, int);
				putchar(ch);
				counter++;
			}
			else if(format[i] == 's')
			{
				char *str = va_arg(ags, char *);
				
				for (j = 0; str[j] != '\0'; j++)
				{
					putchar(str[j]);
					counter++;
				}
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				counter += 2;
			}

		}
		else
		{
			putchar(format[i]);
			counter++;
		}
	}
	va_end(ags);
	return (counter);
}
