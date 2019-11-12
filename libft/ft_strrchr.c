/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:57:13 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/02 20:51:47 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*p;

	len = ft_strlen((char *)s);
	p = (char *)s + len;
	while (*p != (char)c && p > s)
		p--;
	if (!p || (p > 0 && *p != (char)c))
		return (NULL);
	return (p);
}
