#include "shell.h"

/**
 * _putchar - put a char to std out or err
 * @c: the char
 */

void	_putchar(char c)
{
	write(2, &c, 1);
}

/**
 * _putnbr - print a number in stdout or error
 * @nb: the number
 */

void	_putnbr(int nb)
{
	if (nb >= 10)
		_putnbr(nb / 10);
	_putchar(nb % 10 + '0');
}
