/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:08:17 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/24 22:19:24 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		if (ft_putchar(*str) == -1)
			return (-1);
		str++;
		counter++;
	}
	return (counter);
}
