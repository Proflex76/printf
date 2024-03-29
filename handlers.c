#include "main.h"

/****************** WRITE HANDLE ******************/
/**
 * hnadle_write_char - prints a string
 * by Tebogo Mathebula
 * @c: char types.
 * @buffer: Buffer array to handle prints
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: Number of chars printed.
 */

int handle_write_char(char c, char buffer[],
		int flags,, int width, int precision, int size)

{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (writes(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1] width - 1) + 1
					write(1, &buffer[0], 1));
	}
}

}

/****************** WRITE NUMBER ******************/
/**
 * Write_number - prints a string
 * @is_ negative: lista of arguments
 * @ind: char types.
 * @buffer: Buffer arrays to handle print
 * @flags: calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: size specifier
 *
 * Return: Number of chars printed.
 */

int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)

{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && ! (flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_ch));
}

/**
 * write_num - write a number using a buffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: flags
 * @width: width
 * @precision: precision specifier
 * @length: Number length
 * @padd: padding char
 * @extra_c: Extra char
 *
 * B
 * Return: Numbers of printed chars.
 */
int write_num(int ind, char buffer[],
		int flags, int width, int precision,
		int length, char padd, char extra_c)
{
	int i, padd_start = 1;
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0) no char is printed */
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = ' '; /* width is displayed with padding ' ' */
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for ( i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		if (flags & F_MINUS &&padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra[--ind] = extra_c;
					return (write(1, &buffer[ind], lenghth) + write(1, &buffer[1], i - 1));
					}
					else if (!(flags F_MINUS) && padd == ' ') /* extra char to left of buff */
					{
					if (extra_c)
					buffer[--ind] = extra_c;
					return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
					}
					else if (!(flags &F_MINUS) && padd == '0')/* extra char to be left of padd */
					{
					if (extra_c)
					buffer[--padd_start] = extra_c;
					return (write(1, &buffer[padd_start], i - padd_start) +
							write(1, &buffer[ind], length - (1 - padd_start)));
					}
					}
					if (extra_c)
					buffer[--ind] = extra_c;
					return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - writes an unsighned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifier
 * @width: width specifier
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */

int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position i */
	int length = BUFF_SIZE ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0) no  char is printed */

	if (precision == 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		
		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd] */
		{
			return (write(1, buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer] */
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));

}

/**
 * write_pointer - write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: length of number
 * @width: width specifier
 * @flags: flags specifier
 * @padd: char representing the padding
 * @extra_c: char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */

int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start)

{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ') /* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ') /* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0') /* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
