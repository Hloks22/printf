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
			else if (*fmt_ptr == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				printed_chars++;
			}
			else if (*fmt_ptr == 's')
			{
				str = va_arg(args, char *);
				if (str != NULL)
				{
					printf("%s", str);
					printed_chars += strlen(str);
				}
				else
				{
					printf("(null)");
					printed_chars += 6; /* Length of "(null)"*/
				}
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


