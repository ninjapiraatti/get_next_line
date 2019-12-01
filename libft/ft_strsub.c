/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 08:46:19 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/30 20:36:36 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*newstr;

	i = 0;
	if (!s)
		return (NULL);
	if ((newstr = malloc((len) * sizeof(char) + 1)))
	{
		while (i < len)
		{
			newstr[i] = s[start + i];
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	else
		return (NULL);
}
