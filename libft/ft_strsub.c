/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 08:46:19 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/05 09:08:07 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				slen;
	char			*newstr;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
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
