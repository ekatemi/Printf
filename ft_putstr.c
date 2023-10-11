/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:08:17 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/11 20:51:59 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	if (!write(1, &c, 1))
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int counter;

	counter = 0;
	while (*str)
	{
		ft_putchar(*str);
		str++;
		counter++;
	}
	return (counter);
}
