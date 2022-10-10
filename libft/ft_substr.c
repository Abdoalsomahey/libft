/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdabdul <abdabdul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:30:12 by abdabdul          #+#    #+#             */
/*   Updated: 2022/05/31 14:18:55 by abdabdul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*j;

	if (!s)
	{
		return (NULL);
	}
	if (ft_strlen(&s[start]) < len)
	{
		len = ft_strlen(&s[start]);
	}
	j = (char *)malloc(sizeof(char) * (len + 1));
	if (!j)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && s[start + i] && i < len)
	{
		j[i] = s[start + i];
		i++;
	}
	j[i] = '\0';
	return (j);
}
