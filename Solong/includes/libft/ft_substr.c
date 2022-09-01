/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:04:14 by zboutabb          #+#    #+#             */
/*   Updated: 2022/08/30 14:37:00 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
		dst[i++] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	b;

	if (!s)
		return (NULL);
	b = ft_strlen(s) - start;
	if (len > b)
		len = b;
	c = ft_calloc(sizeof(char), 1);
	if (!c)
		return (NULL);
	if (start < ft_strlen(s))
	{
		free(c);
		c = ft_calloc(sizeof(char), len + 1);
		if (!c)
			return (NULL);
		c = ft_copy(c, s + start, len);
	}
	return (c);
}
