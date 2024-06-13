/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:38:50 by poss              #+#    #+#             */
/*   Updated: 2024/05/07 20:42:56 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tokenize/tokenize.h"
#include <stdbool.h>

#define CONVERSION_SPECIFIERS "cspdiuxX%"

static bool	is_specifier(char c);

t_substr	get_next_token(const char *format)
{
	t_substr	token;

	token.start = format;
	if (*format != '%')
	{
		while (*format && *format != '%')
			format++;
		token.len = format - token.start;
	}
	else
	{
		format++;
		while (!is_specifier(*format))
			format++;
		token.len = format + 1 - token.start;
	}
	return (token);
}

static bool	is_specifier(char c)
{
	return (ft_strchr(CONVERSION_SPECIFIERS, c));
}
