/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_es_tu_la.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:25:16 by zboutabb          #+#    #+#             */
/*   Updated: 2022/09/01 12:25:19 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_cmp(const char *s, char c)
{
	size_t	cmpt;

	cmpt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			cmpt++;
		while (*s != c && *s)
			s++;
	}
	return (cmpt);
}

static char	*ft_cpy(const char *s, char c)
{
	char	*str;
	size_t	size;
	size_t	i;

	str = (char *)s;
	size = 0;
	while (*str != c && *str && ++size)
		str++;
	str = malloc(size + 1);
	if (!str)
		return (0);
	i = -1;
	while (++i < size)
		str[i] = *s++;
	str[i] = 0;
	return (str);
}

char	**ft_split(char *s, char c)
{
	size_t	j;
	size_t	size;
	char	**strr;

	if (!s)
		return (0);
	size = ft_cmp(s, c);
	strr = malloc(sizeof(char *) * (size + 1));
	if (!strr)
		return (0);
	j = -1;
	while (++j < size)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			strr[j] = ft_cpy(s, c);
			if (!strr[j])
				return (0);
			s += ft_strlen(strr[j]);
		}
	}
	strr[size] = 0;
	return (strr);
}

int	raren(t_env *env, int i, int sizeline)
{
	if (sizeline != my_strlen(env->map[i]))
	{
		printf("Error\nThat was not a square\n");
		exit(EXIT_FAILURE);
	}
	if (i == 0 || i == ft_linestrlen(env->map))
	{
		if (!ft_special_line(env->map[i]))
		{ 
			printf("Error\nBad first or last line\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!ft_normal_line(env->map[i]))
		{
			printf("Error\nBad line find\n");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

void	freezer(char *s1, char *s2)
{
	free(s1);
	free(s2);
}
