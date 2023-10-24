/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:16:34 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/24 21:26:55 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char	*format, ...)
{
	va_list	arg_ptr;
	int		counter;
	int     ret;

	va_start(arg_ptr, format);
	counter = 0;
	while (*format)
	{
		if (*format != '%')
		{
		  	ret = write (1, format, 1);
			if(ret == -1)
				return(-1);
			counter += ret;
		}
		else
		{
			ret = print_formatted(*(++format), arg_ptr);
			if(ret == -1)
				return(-1);
			counter += ret;
		}
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
		counter = ft_putchar(alpha);
	}
	else if (c == 's')
		counter = ft_putstr(va_arg(arg_ptr, char *));
	else if (c == 'd' || c == 'i')
		counter = ft_putnbr(va_arg(arg_ptr, int));
	else if (c == 'u')
		counter = ft_putnbru(va_arg(arg_ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		counter = ft_putnbrhex(va_arg(arg_ptr, unsigned int), c);
	else if (c == 'p')
		counter = ft_putptr(va_arg(arg_ptr, unsigned long long));
	else if (c == '%')
		counter = ft_putchar(c);
	return (counter);
}
/*
int main(void)
{
	printf("Original: \n	character %c\n	string %s\n	integer %d %i\n	unsigned int %u\n	hexadec %x %X %%\n	end of format", 'a', "Katia", 54 , -54, 258, 123456, -123456);
	printf("\n");
	ft_printf("Mine: \n	character %c\n	string %s\n	integer %d %i\n	unsigned int %u\n	hexadec %x %X %%\n	end of format", 'a', "Katia", 54 , -54, 258, 123456, -123456);

	int i = 3;
	int *ptr = &i;
	printf("\n%p\n", ptr);
	ft_printf("%p",ptr);
}*/
