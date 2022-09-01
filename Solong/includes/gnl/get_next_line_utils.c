/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:07:15 by zboutabb          #+#    #+#             */
/*   Updated: 2021/10/29 13:07:17 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ptr;

	ptr = dest;
	if (src < dest && src + n > dest)
	{
		src = src + n - 1;
		dest = dest + n - 1;
		while (n-- > 0)
			*(char *)dest-- = *(char *)src--;
	}
	else
	{
		if (!dest && !src)
			return (NULL);
		ptr = dest;
		while (n-- > 0)
			*(char *)dest++ = *(char *)src++;
		return (ptr);
	}
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnchr(const char *str, int len, int c)
{
	if (!str)
		return (NULL);
	while (len--)
	{
		if (*str == (char)c)
			return ((char *)str);
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = 0;
	return (res - size);
}
