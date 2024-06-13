/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:46:09 by vlafouas          #+#    #+#             */
/*   Updated: 2024/05/09 09:46:52 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print/print.h"

#define STDOUT 1
#define NULL_STRING_REPR "(null)"

size_t	print_char(va_list *args)
{
	ft_putchar_fd(va_arg(*args, int), STDOUT);
	return (1);
}

size_t	print_string(va_list *args)
{
	const char	*to_print = va_arg(*args, const char *);

	if (!to_print)
		to_print = NULL_STRING_REPR;
	ft_putstr_fd(to_print, STDOUT);
	return (ft_strlen(to_print));
}

size_t	print_literal(t_substr literal)
{
	size_t	i;

	i = 0;
	while (i < literal.len)
		ft_putchar_fd(literal.start[i++], STDOUT);
	return (literal.len);
}

size_t	print_percent(void)
{
	ft_putchar_fd('%', STDOUT);
	return (1);
}
