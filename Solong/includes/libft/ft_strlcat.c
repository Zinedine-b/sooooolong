/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:10:22 by zboutabb          #+#    #+#             */
/*   Updated: 2021/04/23 13:45:58 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_l;
	size_t	src_l;

	src_l = ft_strlen(src);
	dest_l = ft_strlen(dst);
	j = dest_l;
	i = 0;
	if (dest_l < size - 1 && size > 0)
	{
		while (src[i] && dest_l + i < size - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (dest_l >= size)
		dest_l = size;
	return (dest_l + src_l);
}
