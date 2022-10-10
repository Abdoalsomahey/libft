/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdabdul <abdabdul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:52:51 by abdabdul          #+#    #+#             */
/*   Updated: 2022/05/31 16:32:33 by abdabdul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_s_in_set(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	e;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_s_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_s_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(end - start + 1);
	if (!str)
		return (NULL);
	e = 0;
	while (start < end)
		str[e++] = s1[start++];
	str[e] = 0;
	return (str);
}
