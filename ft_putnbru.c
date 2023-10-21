/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:05:55 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/21 23:26:50 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

static int	num_size(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	ft_putnbru(unsigned int n)
{
	char	digit;

	digit = '0';
	if (n >= 0 && n <= 9)
	{
		digit = n + '0';
		write(1, &digit, 1);
	}
	else if (n > 9 && n <= 4294967295)
	{
		ft_putnbru(n / 10);
    	digit = (n % 10) + '0';
    	write(1, &digit, 1);
  }
	return (num_size(n));
}
