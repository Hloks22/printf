#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: list of all types of arguments passed
 * Returns: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *fmt_ptr;
	int printed_chars;
	char *str;
	char c;
	int num;
	unsigned int num1;
	void *ptr;
	
	va_start(args, format);
	printed_chars = 0;

	if (format == NULL)
	{
		return (-1);
	}
	for (fmt_ptr = format; *fmt_ptr != '\0'; fmt_ptr++)
	{
		if (*fmt_ptr == '%')
		{
			fmt_ptr++; /* Move to the next character after '%'*/
			if (*fmt_ptr == '\0')
			{
				break; /* Handle incomplete format specifier*/
			}
			else if (*fmt_ptr == 'd' || *fmt_ptr == 'i')
			{
				num = va_arg(args, int);
				printf("[%d]", num);
				printed_chars += 9; /* Number of chararcters printed */
			}
			else if (*fmt_ptr == 'u')
			{
				num1 = va_arg(args, unsigned int);
				printf("[%u]", num1);
				printed_chars += 4; /* Number of chararcters printed */
			}
			else if (*fmt_ptr == 'o')
			{
				num1 = va_arg(args, unsigned int);
				printf("[%o]", num1);
				printed_chars += 4;
			}
			else if (*fmt_ptr == 'x' || *fmt_ptr == 'X')
			{
				num1 = va_arg(args, unsigned int);
				printf("[%x]", num);
				printed_chars += 9; /* Number of characters printed */
			}
			else if (*fmt_ptr == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				printed_chars++;
			}
			else if (*fmt_ptr == 's')
			{
				str = va_arg(args, char *);
				printf("[%s]", str);
				printed_chars += strlen(str) + 2; /* Number of chararcers to be printed */
			}
			else if (*fmt_ptr == 'p')
			{
				ptr = va_arg(args, void *);
				printf("[%p]", ptr);
				printed_chars += 18; /* Number of characters printed */
			}
			else if (*fmt_ptr == '%')
			{
				putchar('%');
				printed_chars++;
			}
			else
			{
				putchar ('%'); /*Print the '%' character*/
				printed_chars++;
				putchar(*fmt_ptr); /* Print the character as is*/
				printed_chars++;
			}
		}
		else
		{
			putchar(*fmt_ptr);
			printed_chars++;
		}
	}
	va_end(args);
	return (printed_chars);
}


