/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 09:42:53 by tlouekar          #+#    #+#             */
/*   Updated: 2019/10/16 14:25:33 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long int i;

	i = nb;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		i = (i % 10) + '0';
		ft_putchar(i);
	}
	else
	{
		i = i + '0';
		ft_putchar(i);
	}
}
