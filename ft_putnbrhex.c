/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:59:07 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/24 22:20:48 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_putnbrhex(unsigned long n, char base)
{
	char	hex[17];
	int		index;
	int		reminder;
	int		i;

	index = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n != 0)
	{
		reminder = n % 16;
		if (reminder <= 9)
			hex[index++] = reminder + 48;
		else
		{
			if (base == 'X')
				hex[index++] = reminder - 10 + 'A';
			else if (base == 'x')
				hex[index++] = reminder - 10 + 'a';
		}
		n = n / 16;
	}
	hex[index] = '\0';
	i = index - 1;
	while (i >= 0)
	{
		if (write(1, &hex[i--], 1) == -1)
			return (-1);
	}
	return (ft_strlen(hex));
}

int	ft_putptr(unsigned long n)
{
	int	ret;

	ret = write(1, "0x", 2);
	if (ret == -1)
		return (-1);
	return (ret + ft_putnbrhex((unsigned long)n, 'x'));
}

/*
int main()
{
    ft_putnbrhex(-123, 'x');
    printf("\n");
    ft_putnbrhex(-123, 'X');
    printf("\n original %x", -123);
    printf("\n original %X\n", -123);
    //int n = ft_putnbrhex(-123, 'X');
   // printf("\n%d", n);
    return 0;
}*/
