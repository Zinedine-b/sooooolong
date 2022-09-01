/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:12:28 by zboutabb          #+#    #+#             */
/*   Updated: 2021/04/21 14:23:04 by zboutabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(unsigned int nb)
{
	int	resultat;

	resultat = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		resultat++;
	}
	return (resultat);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	int				negatif;
	unsigned int	nbr;

	negatif = 0;
	nbr = n;
	if (n < 0 && ++negatif)
		nbr = -n;
	size = ft_nblen(nbr) + negatif;
	str = malloc(size + 1);
	if (!str)
		return (0);
	str[size] = 0;
	while (size--)
	{
		str[size] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (negatif)
		str[0] = '-';
	return (str);
}
