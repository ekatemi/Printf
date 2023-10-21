/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:16:34 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/21 23:27:57 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	print_formatted(char c, va_list arg_ptr);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbru(unsigned int n);
int	ft_putnbrhex(unsigned int n, char base);
int	ft_putchar(char c);
int	ft_putptr(unsigned long n);

int	ft_printf(const char	*format, ...)
{
	va_list	arg_ptr;
	int		counter;

	va_start(arg_ptr, format);
	counter = 0;
	while (*format)
	{
		if (*format != '%')
			counter += write (1, format, 1);
		else
			counter = counter + print_formatted(*(++format), arg_ptr);
		format++;
	}
	va_end(arg_ptr);
	return (counter);
}

int	print_formatted(char c, va_list arg_ptr)
{
	int		counter;
	char	alpha;

	counter = 0;
	if (c == 'c')
	{
		alpha = (char)va_arg(arg_ptr, int);
		counter += ft_putchar(alpha);
	}
	else if (c == 's')
		counter += ft_putstr(va_arg(arg_ptr, char *));
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(arg_ptr, int));
	else if (c == 'u')
		counter += ft_putnbru(va_arg(arg_ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		counter += ft_putnbrhex(va_arg(arg_ptr, unsigned int), c);
	else if (c == 'p')
		counter += ft_putptr(va_arg(arg_ptr, unsigned long long));
	else if (c == '%')
		counter += ft_putchar(c);
	return (counter);
}

int main(void)
{
	printf("Original: \n	character %c\n	string %s\n	integer %d %i\n	unsigned int %u\n	hexadec %x %X %%\n	end of format", 'a', "Katia", 54 , -54, 258, 123456, -123456);
	printf("\n");
	ft_printf("Mine: \n	character %c\n	string %s\n	integer %d %i\n	unsigned int %u\n	hexadec %x %X %%\n	end of format", 'a', "Katia", 54 , -54, 258, 123456, -123456);

	int i = 3;
	int *ptr = &i;
	printf("\n%p\n", ptr);
	ft_printf("%p",ptr);
}
