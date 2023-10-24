/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emikhayl <emikhayl@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:42:59 by emikhayl          #+#    #+#             */
/*   Updated: 2023/10/24 19:50:15 by emikhayl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	print_formatted(char c, va_list arg_ptr);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbru(unsigned int n);
int	ft_putnbrhex(unsigned int n, char base);
int	ft_putchar(char c);
int	ft_putptr(unsigned long n);
int	ft_printf(const char	*format, ...);

#endif
