/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdabdul <abdabdul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:52:09 by abdabdul          #+#    #+#             */
/*   Updated: 2022/05/17 09:53:20 by abdabdul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str12;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str12 = (char *)malloc(sizeof(char) * (len + 1));
	if (!str12)
		return (NULL);
	while (s1[i] != '\0')
	{
		str12[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str12[i] = s2[j];
		j++;
		i++;
	}
	str12[i] = '\0';
	return (str12);
}
