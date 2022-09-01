/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:06:29 by zboutabb          #+#    #+#             */
/*   Updated: 2022/08/30 15:03:42 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include	<stdlib.h>
# include	<unistd.h>
# include   "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
//void	*ft_memmove(void *dest, const void *src, size_t n);
//char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strnchr(const char *str, int len, int c);
void	ft_bzero(void *ptr, size_t len);
char	*get_next_line(int fd);

#endif
