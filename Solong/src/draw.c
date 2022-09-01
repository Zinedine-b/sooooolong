/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:06:39 by zboutabb          #+#    #+#             */
/*   Updated: 2022/08/30 15:08:49 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_env *env, int x, int y, unsigned int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < env->win_l && y < env->win_h))
	{	
		dst = env->img->addr + (y * env->img->line_length + x * \
				(env->img->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	draw_square(t_env *env, int currentx, int currenty, unsigned int color)
{
	int	a;
	int	b;

	a = currentx;
	while (a < currentx + SIZE)
	{
		b = currenty;
		while (b < currenty + SIZE)
		{
			my_mlx_pixel_put(env, b, a, color);
			b++;
		}
		a++;
	}
}

unsigned int	ft_color(t_env *env, int x, int y)
{
	if (env->map[x][y] == '1')
		return (WHITE);
	if (env->map[x][y] == '0')
		return (BLUE);
	if (env->map[x][y] == 'C')
		return (GREEN);
	if (env->map[x][y] == 'P')
		return (MAROON);
	if (env->map[x][y] == 'E')
		return (RED);
	return (BLACK);
}

void	ft_draw(t_env *env)
{
	int				i;
	int				j;
	unsigned int	color;

	env->img->data = mlx_new_image(env->mlx, env->win_l, env->win_h);
	env->img->addr = mlx_get_data_addr(env->img->data, \
			&env->img->bits_per_pixel, &env->img->line_length,
			&env->img->endian);
	i = 0;
	env->startx = -1;
	while (++env->startx < env->size_h)
	{
		j = 0;
		env->starty = -1;
		while (++env->starty < env->size_l)
		{
			j += 64;
			color = ft_color(env, env->startx, env->starty);
			draw_square(env, i, j, color);
		}
		i += 64;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->data, 0, 0);
}
