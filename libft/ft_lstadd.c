/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:57:48 by tlouekar          #+#    #+#             */
/*   Updated: 2019/12/02 09:20:24 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst && *alst)
	{
		temp = *alst;
		*alst = new;
		(*alst)->next = temp;
	}
	else
		*alst = new;
}
