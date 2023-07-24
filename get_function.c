#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * get_function - function to get the appropriate print function
 * @specifier: the specifier
 * Return: returns the print function
 */
print_func get_function(char specifier)
{
	switch (specifier)
	{
		case 'c':
			return (&print_char);
		case 's':
			return (&print_string);
		case 'd':
		case 'i':
			return (&print_integer);
		default:
			return (NULL);
	}
}
