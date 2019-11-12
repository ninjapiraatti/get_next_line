/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:04:06 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/05 09:09:09 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	i = 0;
	j = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if ((newstr = (char *)malloc(sizeof(char) * len + 1)))
	{
		while (s1[i] != '\0')
		{
			newstr[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			newstr[i + j] = s2[j];
			j++;
		}
		newstr[i + j] = '\0';
		return (newstr);
	}
	else
		return (NULL);
}
