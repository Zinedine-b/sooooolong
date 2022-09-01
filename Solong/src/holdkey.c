/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   holdkey.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:09:25 by zboutabb          #+#    #+#             */
/*   Updated: 2022/08/30 15:09:33 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_make_move(t_env *env, int x, int y)
{
	if (env->map[x][y] == 'C')
	{
		env->map[x][y] = 'P';
		env->map[env->posx][env->posy] = '0';
		env->posx = x;
		env->posy = y;
		env->parse->collectible--;
	}
	else if (env->map[x][y] == 'E' && env->parse->collectible == 0)
	{
		printf("gg tu as win \n");
		ft_cleanup(env);
	}
	else if (env->map[x][y] == '0')
	{
		env->map[x][y] = 'P';
		env->map[env->posx][env->posy] = '0';
		env->posx = x;
		env->posy = y;
	}
	env->totalmove++;
}

void	ft_move(t_env *env, int mode)
{
	int	x;
	int	y;

	x = env->posx;
	y = env->posy;
	if (mode == 1)
		x = env->posx - 1;
	if (mode == 0)
		x = env->posx + 1;
	if (mode == 2)
		y = env->posy - 1;
	if (mode == 3)
		y = env->posy + 1;
	if (x <= 0 || y <= 0 || x >= env->size_h || y >= env->size_l)
		return ;
	ft_make_move(env, x, y);
	ft_draw(env);
	printf("%d\n", env->totalmove);
}

int	holdkey(int signal, t_env *env)
{
	if (signal == KEY_S)
		ft_move(env, 0);
	if (signal == KEY_W)
		ft_move(env, 1);
	if (signal == KEY_A)
		ft_move(env, 2);
	if (signal == KEY_D)
		ft_move(env, 3);
	if (signal == KEY_ESC)
		ft_cleanup(env);
	return (0);
}
