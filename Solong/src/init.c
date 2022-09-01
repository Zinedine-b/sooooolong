/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:09:47 by zboutabb          #+#    #+#             */
/*   Updated: 2022/08/30 15:10:05 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_pars(t_pars *tmp)
{
	tmp->collectible = 0;
	tmp->exit = 0;
	tmp->fd = 0;
	tmp->player = 0;
}

void	ft_init_env(t_env *env)
{
	env->endx = 0;
	env->endy = 0;
	env->map = NULL;
	env->posx = 0;
	env->posy = 0;
	env->startx = 0;
	env->starty = 0;
	env->size_h = 0;
	env->size_l = 0;
	env->totalmove = 0;
}

int	ft_cleanup(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit (1);
	return (0);
}
