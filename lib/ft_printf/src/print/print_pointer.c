/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:49:28 by vlafouas          #+#    #+#             */
/*   Updated: 2024/05/09 22:11:15 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print/print.h"

#define STDOUT 1
#define NULL_POINTER_REPR "0x0"
#define LOWERCASE_HEX "0123456789abcdef"
#define POINTER_PREFIX "0x"

size_t	print_pointer(va_list *args)
{
	const void	*to_print = va_arg(*args, void *);

	if (to_print == NULL)
	{
		ft_putstr_fd(NULL_POINTER_REPR, STDOUT);
		return (ft_strlen(NULL_POINTER_REPR));
	}
	ft_putstr_fd(POINTER_PREFIX, STDOUT);
	ft_put_unsigned((uint64_t)to_print, LOWERCASE_HEX);
	return (ft_strlen(POINTER_PREFIX) + get_n_digits((uint64_t)to_print,
			ft_strlen(LOWERCASE_HEX)));
}
