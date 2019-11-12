/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:57:43 by tlouekar          #+#    #+#             */
/*   Updated: 2019/10/29 10:28:07 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(long n)
{
	int		i;

	i = 1;
	while (n / 10 >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;
	long	nb;

	neg = 0;
	nb = (long)n;
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	len = intlen(nb) + neg;
	if (!(str = (char *)malloc((sizeof(char) * len + 1))))
		return (NULL);
	if (neg > 0)
		str[0] = '-';
	str[len] = '\0';
	while (len >= (1 + neg))
	{
		str[len - 1] = 48 + (nb % 10);
		nb = nb / 10;
		len--;
	}
	return (str);
}