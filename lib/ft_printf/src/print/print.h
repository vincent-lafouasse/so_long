/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:32:45 by poss              #+#    #+#             */
/*   Updated: 2024/05/09 09:46:08 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "tokenize/tokenize.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

size_t	print_token(t_substr token, va_list *args);

size_t	print_unsigned(va_list *args, const char *charset);
size_t	print_integer(va_list *args);
size_t	print_pointer(va_list *args);

size_t	print_char(va_list *args);
size_t	print_string(va_list *args);
size_t	print_literal(t_substr literal);
size_t	print_percent(void);

void	ft_put_unsigned(uint64_t n, const char *charset);
size_t	get_n_digits(uint64_t n, size_t base);
#endif
