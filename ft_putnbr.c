/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:35:57 by emikhayl          #+#    #+#             */
/*   Updated: 2023/11/03 23:19:47 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_write_num(int nb)
{
	int		temp;
	int		digits;
	int		i;
	char	numero_arr[11];

	temp = nb;
	digits = 1;
	while (temp >= 10)
	{
		temp = temp / 10;
		digits++;
	}
	i = digits - 1;
	while (i >= 0)
	{
		numero_arr[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (write (1, numero_arr, digits));
}

int	ft_putnbr(int nb)
{
	int	counter;

	counter = 0;
	if (nb < 0 && nb != -2147483648)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		counter += 1;
	}
	if (nb == -2147483648)
	{
		if (write(1, "-2", 2) == -1)
			return (-1);
		nb = 147483648;
		counter += 2;
	}
	return (counter + ft_write_num(nb));
}

/*
int main()
{
    int x = ft_putnbr(-2147483648);
    printf("\n%d", x);
    return 0;
}*/
