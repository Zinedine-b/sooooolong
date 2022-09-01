/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:25:04 by zboutabb          #+#    #+#             */
/*   Updated: 2022/09/01 12:25:08 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_char_accepted(char c, t_env *env, int x, int y)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
		return (0);
	if (c == 'P' && !env->parse->player)
	{
		env->parse->player++;
		env->posx = x;
		env->posy = y;
	}
	else if (c == 'P' && env->parse->player)
	{
		printf("Error\n 2 player found\n");
		return (0);
	}
	if (c == 'E')
		env->parse->exit++;
	if (c == 'C')
		env->parse->collectible++;
	return (1);
}

int	ft_all_char(char **tab, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				if (!ft_char_accepted(tab[i][j], env, i, j))
					return (0);
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_linestrlen(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

int	ft_special_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_normal_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] != '1')
				return (0);
		}
		i++;
	}
	if (str[--i] != '1')
		return (0);
	return (1);
}
