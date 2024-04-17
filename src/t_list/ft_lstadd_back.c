/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:54:25 by poss              #+#    #+#             */
/*   Updated: 2024/04/17 15:28:33 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

#include <stddef.h>

void ft_lstadd_back(t_list** lst, t_list* new)
{
    t_list* back;

    if (lst == NULL)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    back = ft_lstlast(*lst);
    back->next = new;
}
