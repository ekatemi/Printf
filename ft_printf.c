/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:16:34 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/12 19:57:58 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int print_formatted(char c, va_list arg_ptr);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putnbru(unsigned int n);
int ft_putnbrhex(unsigned int n, char base);

int ft_printf(const char *format, ...)
{
	va_list arg_ptr;
	int counter;
	
	va_start(arg_ptr, format);
	counter = 0;
	while (*format)
	{
		if (*format != '%')
			counter = counter + write (1, format, 1);
		else 
			counter = counter + print_formatted(*(++format), arg_ptr);
	format++;
	}
	va_end(arg_ptr);
	return (counter);
}

int print_formatted(char c, va_list arg_ptr)
{
	int counter;

	counter = 0;
	if (c == 'c')
	{
		c = va_arg(arg_ptr, int);
		counter += write(1, &c, 1);
	}
	else if (c == 's')
	{
		char *str = va_arg(arg_ptr, char *);
		counter += ft_putstr(str);
	}
	else if (c == 'd' || c == 'i')
	{
		c = va_arg(arg_ptr, int);
		counter += ft_putnbr(c);
	}
	else if (c == 'u')
	{
		c = va_arg(arg_ptr, unsigned int);
		counter += ft_putnbru(c);
	}
	else if (c == 'x' || c == 'X')
		c = va_arg(arg_ptr, unsigned int);
		counter += ft_putnbrhex(c, base);
	return (counter);
}



int main(void)
{
	printf("Original  %s %c %d %i %u %x %X\n", "Katia", 'N', 123, -123, UINT_MAX, 1234567, 1234567);
	ft_printf("Mine %s %c %d %i %u %x %x", "Katia", 'N', 123, -123, 4294967295, 1234567, 1234567);
}
