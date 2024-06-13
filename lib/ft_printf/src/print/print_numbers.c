/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:38:21 by vlafouas          #+#    #+#             */
/*   Updated: 2024/05/09 09:47:33 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print/print.h"

#define STDOUT 1

static unsigned int	ft_abs(int n);

size_t	print_integer(va_list *args)
{
	int	to_print;

	to_print = va_arg(*args, int);
	ft_putnbr_fd(to_print, STDOUT);
	if (to_print == 0)
		return (1);
	return ((to_print < 0) + get_n_digits(ft_abs(to_print), 10));
}

size_t	print_unsigned(va_list *args, const char *charset)
{
	uint64_t	to_print;

	to_print = va_arg(*args, unsigned int);
	ft_put_unsigned(to_print, charset);
	if (to_print == 0)
		return (1);
	return (get_n_digits(to_print, ft_strlen(charset)));
}

void	ft_put_unsigned(uint64_t n, const char *charset)
{
	size_t	base;

	base = ft_strlen(charset);
	if (n < base)
		ft_putchar_fd(charset[n], STDOUT);
	else
	{
		ft_put_unsigned(n / base, charset);
		ft_put_unsigned(n % base, charset);
	}
}

size_t	get_n_digits(uint64_t n, size_t base)
{
	size_t	n_digits;

	n_digits = 0;
	while (n)
	{
		n_digits++;
		n /= base;
	}
	return (n_digits);
}

static unsigned int	ft_abs(int n)
{
	return (((n >= 0) - (n < 0)) * n);
}
