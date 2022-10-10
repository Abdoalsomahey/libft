/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdabdul <abdabdul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:47:15 by abdabdul          #+#    #+#             */
/*   Updated: 2022/05/25 21:46:26 by abdabdul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
