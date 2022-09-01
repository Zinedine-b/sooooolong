/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:28:50 by zboutabb          #+#    #+#             */
/*   Updated: 2021/04/07 13:30:37 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *t, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (*t == '\0')
		return ((char *)s);
	i = 0;
	while (s[i] && i < n)
	{
		j = 0;
		while (s[i + j] && t[j] && i + j < n && s[i + j] == t[j])
			j++;
		if (!t[j])
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
