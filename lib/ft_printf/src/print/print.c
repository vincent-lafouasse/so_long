/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:35:32 by poss              #+#    #+#             */
/*   Updated: 2024/05/09 09:46:26 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print/print.h"
#include <stdbool.h>

#define STDOUT 1
#define NULL_POINTER_REPR "(nil)"
#define DECIMAL "0123456789"
#define LOWERCASE_HEX "0123456789abcdef"
#define UPPERCASE_HEX "0123456789ABCDEF"

static bool	token_is_literal(t_substr token);
static char	get_specifier(t_substr token);

size_t	print_token(t_substr token, va_list *args)
{
	char	conversion_specifier;

	if (token_is_literal(token))
		return (print_literal(token));
	conversion_specifier = get_specifier(token);
	if (ft_strchr("id", conversion_specifier))
		return (print_integer(args));
	if (conversion_specifier == '%')
		return (print_percent());
	if (conversion_specifier == 'c')
		return (print_char(args));
	if (conversion_specifier == 'u')
		return (print_unsigned(args, DECIMAL));
	if (conversion_specifier == 'x')
		return (print_unsigned(args, LOWERCASE_HEX));
	if (conversion_specifier == 'X')
		return (print_unsigned(args, UPPERCASE_HEX));
	if (conversion_specifier == 's')
		return (print_string(args));
	if (conversion_specifier == 'p')
		return (print_pointer(args));
	return (0);
}

static bool	token_is_literal(t_substr token)
{
	return (token.len == 0 || token.start[0] != '%');
}

static char	get_specifier(t_substr token)
{
	return (token.start[token.len - 1]);
}
