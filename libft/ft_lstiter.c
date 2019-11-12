/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:41:49 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/02 18:19:11 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*next;

	if (lst && f)
	{
		temp = lst;
		while (temp)
		{
			next = temp->next;
			f(temp);
			temp = next;
		}
	}
}
