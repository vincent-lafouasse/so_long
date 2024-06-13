/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:13:00 by poss              #+#    #+#             */
/*   Updated: 2024/05/09 22:13:49 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	const char	*int_min = "int min";

	ft_printf("hel");
	ft_printf("");
	ft_printf("lo\n\n");
	ft_printf("Voici %s: %d\n", "int max", INT_MAX);
	printf("On devrait voir %d\n", INT_MAX);
	ft_printf("Et voici %s: %d\n", int_min, INT_MIN);
	printf("On devrait voir %d\n", INT_MIN);
	ft_printf("%x\n", 0xBABECAFE);
	ft_printf("%X\n", 0xBABECAFE);
	ft_printf("%p\n", (void *)0xBABECAFE);
}
