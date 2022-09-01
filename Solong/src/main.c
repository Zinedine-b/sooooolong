/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:24:52 by zboutabb          #+#    #+#             */
/*   Updated: 2022/09/01 12:24:56 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_start_parse(t_env *env, char *str)
{
	if (!try_extension(str))
		exit_with_error_msg("Error\n Invalid extension\n");
	if (!try_open(str, env))
		exit_with_error_msg("Error\n Invalid Format of file \n");
}

int	ft_good_format_map(t_env *env, int i, int sizeline)
{
	if (!ft_all_char(env->map, env))
	{
		printf("Error\n Bad char find\n");
		exit(EXIT_FAILURE);
	}
	while (env->map[++i])
	{
		if (raren(env, i, sizeline) == 0)
			return (0);
	}
	return (1);
}

void	ft_parse(t_env *env)
{
	char	*tmp;
	char	*line;

	tmp = NULL;
	line = get_next_line(env->parse->fd);
	while (line)
	{
		tmp = my_join(tmp, line);
		line = get_next_line(env->parse->fd);
	}
	env->map = ft_split(tmp, '\n');
	if (!ft_good_format_map(env, -1, my_strlen(env->map[0])))
		return ;
	if (!env->parse->player || !env->parse->exit || !env->parse->collectible)
	{
		printf("Error\n Mandatory data needed\n");
		return ;
	}
	env->size_l = my_strlen(env->map[0]);
	env->size_h = ft_linestrlen(env->map);
	free(tmp);
}

int	main(int ac, char **av)
{
	t_env	env;
	t_img	img;
	t_pars	pars;

	ft_init_pars(&pars);
	ft_init_env(&env);
	env.img = &img;
	env.parse = &pars;
	if (ac != 2)
		exit_with_error_msg("Error\n Invalid number of argument\n");
	ft_start_parse(&env, av[1]);
	ft_parse(&env);
	env.win_h = (env.size_h) * 64;
	env.win_l = (env.size_l) * 64;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.win_l, env.win_h, "Solong");
	ft_draw(&env);
	mlx_hook(env.win, 2, 0, holdkey, &env);
	mlx_hook(env.win, 17, 0, ft_cleanup, &env);
	mlx_loop(env.mlx);
	return (0);
}
