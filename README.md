# 0x11. C - printf
## The Domains/Concepts covered in this project: `C programming` `Group project`

Compilation

  * Your code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```
  * As a consequence, be careful not to push any c file containing a `main` function in the root directory of your project (you could have a `test` folder containing all your tests files including `main` functions)
  * Our main files will include your main header file (`main.h`): `#include main.h`
  * You might want to look at the gcc flag `-Wno-format` when testing with your `_printf` and the standard `printf`. Example of test file that you could use:

```
alex@ubuntu:~/c/printf$ cat main.c 
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
alex@ubuntu:~/c/printf$ ./printf
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Address:[0x7ffe637541f0]
Address:[0x7ffe637541f0]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]
alex@ubuntu:~/c/printf$
```


  * We strongly encourage you to work all together on a set of tests
  * If the task does not specify what to do with an edge case, do the same as `printf`

## Tasks :page_with_curl:

**0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life**

Write a function that produces output according to a format.

  * Prototype: `int _printf(const char *format, ...);`
  * Returns: the number of characters printed (excluding the null byte used to end output to strings)
  * write output to stdout, the standard output stream
  * `format` is a character string. The format string is composed of zero or more directives. See `man 3 printf` for more detail. You need to handle the following conversion specifiers:
    * `c`
    * `s`
    * `%`
  * You don’t have to reproduce the buffer handling of the C library `printf` function
  * You don’t have to handle the flag characters
  * You don’t have to handle field width
  * You don’t have to handle precision
  * You don’t have to handle the length modifiers

  * [printf](./printf)

**1. Education is when you read the fine print. Experience is what you get if you don't**

Handle the following conversion specifiers:

  * `d`
  * `i`
  * You don’t have to handle the flag characters
  * You don’t have to handle field width
  * You don’t have to handle precision
  * You don’t have to handle the length modifiers

  * [printf](./printf)

**2. With a face like mine, I do better in print**

Handle the following custom conversion specifiers:

  * `b`: the unsigned int argument is converted to binary

```
alex@ubuntu:~/c/printf$ cat main.c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%b\n", 98);
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
1100010
alex@ubuntu:~/c/printf$
```

  * [printf](./printf)

**3. What one has not experienced, one will never understand in print**

Handle the following conversion specifiers:

  * `u`
  * `o`
  * `x`
  * `X`
  * You don’t have to handle the flag characters
  * You don’t have to handle field width
  * You don’t have to handle precision
  * You don’t have to handle the length modifiers

  * [printf](./printf)

**4. Nothing in fine print is ever good news**

Use a local buffer of 1024 chars in order to call `write` as little as possible.

  * [printf](./printf)

**5. My weakness is wearing too much leopard print**

Handle the following custom conversion specifier:

  * `S` : prints the string.
  * Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: `\x`, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

```
alex@ubuntu:~/c/printf$ cat main.c
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("%S\n", "Best\nSchool");
    return (0);
}
alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
alex@ubuntu:~/c/printf$ ./a.out
Best\x0ASchool
alex@ubuntu:~/c/printf$
```

  * [printf](./printf)

**6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print**

Handle the following conversion specifier: `p`.

  * You don’t have to handle the flag characters
  * You don’t have to handle field width
  * You don’t have to handle precision
  * You don’t have to handle the length modifiers

  * [printf](./printf)

**7. The big print gives and the small print takes away**

Handle the following flag characters for non-custom conversion specifiers:

  * `+`
  * space
  * `#`

  * [printf](./printf)

**8. Sarcasm is lost in print**

Handle the following length modifiers for non-custom conversion specifiers:

  * `l`
  * `h`

Conversion specifiers to handle: `d`, `i`, `u`, `o`, `x`, `X`

  * [printf](./printf)

**9. Print some money and give it to us for the rain forests**

Handle the field width for non-custom conversion specifiers.

  * [printf](printf)

**10. The negative is the equivalent of the composer's score, and the print the performance**

Handle the precision for non-custom conversion specifiers.

  * [printf](./printf)

**11. It's depressing when you're still around and your albums are out of print**

Handle the `0` flag character for non-custom conversion specifiers.

  * [printf](./printf)

**12. Every time that I wanted to give up, if I saw an interesting textile, print what ever, suddenly I would see a collection**

Handle the - flag character for non-custom conversion specifiers.

  * [printf](./printf)

**13. Print is the sharpest and the strongest weapon of our party**

Handle the following custom conversion specifier:

    * `r` : prints the reversed string
  * [printf](./printf)

**14. The flood of print has turned reading into a process of gulping rather than savoring**

Handle the following custom conversion specifier:

    * `R`: prints the rot13'ed string

  * [printf](./printf)

**15. ***

All the above options work well together.

Well done on completing this project! Let the world hear about this milestone achieved.

## Additional Project Resources

  * [Printf function brief - What to know to create your own Printf function](https://docs.google.com/document/d/1P92WHtfsWZKy91FdBhgaT6zrcGvrY0SLNbpOtkj3K1g/edit?usp=sharing)
  * [All about Team Projects + Pairings + FAQ (A must read)](https://docs.google.com/document/d/1P92WHtfsWZKy91FdBhgaT6zrcGvrY0SLNbpOtkj3K1g/edit?usp=sharing)
  * [Group Projects](https://docs.google.com/document/d/1P92WHtfsWZKy91FdBhgaT6zrcGvrY0SLNbpOtkj3K1g/edit?usp=sharing)
  * [Flowcharts](https://docs.google.com/document/d/1P92WHtfsWZKy91FdBhgaT6zrcGvrY0SLNbpOtkj3K1g/edit?usp=sharing)
  * [Pair Programming - How To](https://docs.google.com/document/d/1P92WHtfsWZKy91FdBhgaT6zrcGvrY0SLNbpOtkj3K1g/edit?usp=sharing)
  * [Technical Writing](https://docs.google.com/document/d/1P92WHtfsWZKy91FdBhgaT6zrcGvrY0SLNbpOtkj3K1g/edit?usp=sharing)
