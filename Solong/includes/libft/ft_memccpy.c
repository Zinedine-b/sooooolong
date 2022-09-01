/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:00:39 by zboutabb          #+#    #+#             */
/*   Updated: 2021/04/12 16:08:18 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*oct1;
	unsigned char	*oct2;

	oct1 = (unsigned char *)dst;
	oct2 = (unsigned char *)src;
	while (n--)
	{
		*oct1 = *oct2;
		if (*oct1 == (unsigned char)c)
			return (oct1 + 1);
		oct1++;
		oct2++;
	}
	return (NULL);
}
