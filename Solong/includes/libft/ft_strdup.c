/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:00:01 by zboutabb          #+#    #+#             */
/*   Updated: 2021/04/07 16:01:45 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	a;
	size_t	b;
	char	*res;

	a = 0;
	b = 0;
	while (src[a])
	{
		a++;
	}
	res = malloc(sizeof(char) * a + 1);
	if (res == NULL)
		return (NULL);
	while (src[b] != '\0')
	{
		res[b] = src[b];
		b++;
	}
	res[b] = '\0';
	return (res);
}
