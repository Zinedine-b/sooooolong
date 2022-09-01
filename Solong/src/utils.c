/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:25:25 by zboutabb          #+#    #+#             */
/*   Updated: 2022/09/01 12:25:28 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	try_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if (str[i + 1] && str[i + 1] == 'b')
				if (str[i + 2] && str[i + 2] == 'e')
					if (str[i + 3] && str[i + 3] == 'r')
						return (1);
		i++;
	}
	return (0);
}

int	try_open(char *str, t_env *env)
{
	env->parse->fd = open(str, O_DIRECTORY);
	if (env->parse->fd > 0)
		exit_with_error_msg("Error\n Path is a directory\n");
	env->parse->fd = open(str, O_RDONLY);
	if (env->parse->fd < 0)
		exit_with_error_msg("Error\n Invalid path\n");
	return (1);
}

void	exit_with_error_msg(char *str)
{
	printf("%s", str);
	exit(1);
}

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*my_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = -1;
	new = malloc(my_strlen(s1) + my_strlen(s2) + 2);
	if (!new)
		return (NULL);
	if (s1)
	{
		while (s1[++i])
			new[i] = s1[i];
	}
	else
		i = 0;
	if (s2)
	{
		while (s2[++j])
			new[i + j] = s2[j];
	}
	new[i + j] = '\n';
	new[i + j + 1] = 0;
	freezer(s1, s2);
	return (new);
}
