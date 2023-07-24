#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
/*function pointer typedef for the helper functions*/
typedef void (*print_func)(va_list args, int *counter);
/*function prototypes for helper functions*/
void print_char(va_list args, int *counter);
void print_string(va_list args, int *counter);
void print_integer(va_list args, int *counter);
/*function that gets the function pointer based on the conversion specifier*/
print_func get_function(char specifier);
/*_printf function prototype*/
int _printf(const char *format, ...);
#endif
