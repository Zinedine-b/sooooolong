/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:31:40 by zboutabb          #+#    #+#             */
/*   Updated: 2022/08/30 14:56:48 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
//# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "../includes/libft/libft.h"
# include "unistd.h"
# include "stdio.h"
# include <fcntl.h>

# define TRANSPARANT	0xFFFFFFFF
# define BLACK			0x00000000
# define GRAY			0x00808080
# define SILVER			0x00C0C0C0
# define WHITE			0x00FFFFFF
# define NAVY			0x00000080
# define BLUE			0x000000FF
# define TEAL			0x00008080
# define AQUA			0x0000FFFF
# define GREEN			0x00008000
# define LIME			0x0000FF00
# define OLIVE			0x00808000
# define YELLOW			0x00FFFF00
# define MAROON			0x00800000
# define RED			0x00FF0000
# define PURPLE			0x00800080
# define FUCHSIA		0x00FF00FF
# define DARK_BLUE		0x003e6358
# define LIGHT_CYAN		0x006eccc4

# define SIZE			64
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_EVENT_PRESS 2
# define KEY_EVENT_EXIT 17
# define KEY_EVENT_RELEASE 3

typedef struct s_img
{
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_pars
{
	int	fd;
	int	collectible;
	int	player;
	int	exit;
}				t_pars;

typedef struct s_env
{
	char	**map;
	int		size_l;
	int		size_h;
	t_img	*img;
	t_pars	*parse;
	void	*mlx;
	void	*win;
	int		startx;
	int		starty;
	int		endx;
	int		endy;
	int		posx;
	int		posy;
	int		win_h;
	int		win_l;
	int		totalmove;
}				t_env;

int		raren(t_env *env, int i, int sizeline);
int		holdkey(int signal, t_env *env);
void	exit_with_error_msg(char *str);
void	ft_init_env(t_env *env);
void	ft_init_pars(t_pars *tmp);
int		try_extension(char *str);
int		try_open(char *str, t_env *env);
char	*my_join(char *s1, char *s2);
int		my_strlen(char *str);
void	ft_draw(t_env *env);
int		ft_cleanup(t_env *env);
char	**ft_split(char *str, char c);
int		ft_normal_line(char *str);
int		ft_special_line(char *str);
int		ft_linestrlen(char **tab);
int		ft_all_char(char **tab, t_env *env);
int		ft_char_accepted(char c, t_env *env, int i, int j);
void	freezer(char *s1, char *s2);

#endif
