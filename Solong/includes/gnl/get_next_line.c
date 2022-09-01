/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:04:30 by zboutabb          #+#    #+#             */
/*   Updated: 2021/10/29 13:08:34 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_secure(char **save, char **streturn, char *word_read, int i)
{
	char	c;

	if (!*streturn)
	{
		c = word_read[i + 1];
		word_read[i + 1] = '\0';
		*streturn = ft_strjoin(word_read, "");
		word_read[i + 1] = c;
	}
	else
	{
		*save = *streturn;
		c = word_read[i + 1];
		word_read[i + 1] = '\0';
		*streturn = ft_strjoin(*save, word_read);
		word_read[i + 1] = c;
		free(*save);
	}
}

void	ft_move_all(char **save, char *word_read, char **strreturn)
{
	if (!*strreturn)
		*strreturn = ft_strjoin(word_read, "");
	else
	{
		*save = *strreturn;
		*strreturn = ft_strjoin(*save, word_read);
		free(*save);
	}
	word_read[0] = '\0';
}

void	ft_move_piece(char **save, char *word_read,
		char **streturn, int *char_r)
{
	int	i;

	if (ft_strnchr(word_read, BUFFER_SIZE, '\n'))
		*char_r = 0;
	i = 0;
	while (word_read[i] != '\n' && word_read[i])
		++i;
	ft_secure(save, streturn, word_read, i);
	++i;
	ft_memmove(word_read, &word_read[i], BUFFER_SIZE - i);
	word_read[BUFFER_SIZE - i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	word_read[BUFFER_SIZE + 1];
	char		*save;
	char		*streturn;
	int			nb_read_char;

	nb_read_char = 1;
	streturn = NULL;
	if (*word_read)
		ft_move_piece(&save, word_read, &streturn, &nb_read_char);
	while (nb_read_char)
	{
		nb_read_char = read(fd, word_read, BUFFER_SIZE);
		if (nb_read_char == -1)
			return (NULL);
		word_read[nb_read_char] = '\0';
		if (nb_read_char == BUFFER_SIZE && !ft_strnchr(word_read,
				BUFFER_SIZE, '\n'))
			ft_move_all(&save, word_read, &streturn);
		else if (nb_read_char)
			ft_move_piece(&save, word_read, &streturn, &nb_read_char);
	}
	return (streturn);
}
