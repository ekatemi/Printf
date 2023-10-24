/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:35:57 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/24 21:59:39 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int num_size(int num)
{
  int len = 0;
  if (num <= 0)
    {
      len++;
      num = -num;
    }
  while(num != 0)
    {
      num = num / 10;
      len++;
    }
    return len;
}

int ft_putnbr(int n)
{
	int x;
 
	x = n;
  	char digit = '0';
	if (n == -2147483648)
	{
		if (write(1, "-2", 2) == -1)
			return(-1);
		n = 147483648;
    }
	if (n < 0)
	{
		if(write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		digit = n + '0';
		if(write(1, &digit, 1) == -1)
			return(-1);
	}
	else
	{
		if(ft_putnbr(n / 10) == -1)
			return (-1);
		digit = (n % 10) + '0';
		if(write(1, &digit, 1) == -1)
			return(-1);
	}
	return(num_size(x));
}
/*
int main()
{
    int x = ft_putnbr(-2147483648);
    printf("\n%d", x);
    return 0;
}*/
