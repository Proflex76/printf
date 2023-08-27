#include "main.h"

/****************** PRINT UNSIGNED NUMBER ******************/
/**
 * print_unsigned - prints an unsigned number
 * by Tebogo Mathebula
 * @types: list of arguments
 * @buffer: buffer array to handle flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of chars printed.
 */

int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0; i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL *************/
/**
 * print_octal - prints an unsigned number in octal notation
 * @btypes: list of argumunts
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of cjars printed
 */

int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUZZ-SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED IN HEXADECIMAL **************/
/**
 * print_hexidecimal - prints an unsigned number in hexidecimal notation
 * @types: list of arguments
 * @buffer: buffer array to  handle print
 * flags: calculate active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of chars printed
 */

int print_hexidecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN UPPER HEXIDECIMAL **************/
/**
 * print_hexa_upper - prints am umsigned number in upper hexidecimal notation
 * @types: list of arguments
 * @buffer: buffer array to handle prints
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of chars printed
 */

int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa_upper(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - prints a hexadecimal number in lower or upper
 * @types: list of arguments
 * @map_to: Array of values to map the number to
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @flag_ch: calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, int char_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE -2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
