/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:52:38 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/28 13:32:05 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_intlen(long int nb, char z)
{
	long int	i;
	long int	nbr;

	i = 0;
	if (!nb)
		return (1);
	if (nb < 0)
		nbr = -nb * 10;
	else
		nbr = nb;
	if (z == 'd' || z == 'i')
	{
		while (nbr)
		{
			nbr /= 10;
			i++;
		}
		return (i);
	}
	if (z == 'x')
	{
		while (nbr)
		{
			nbr /= 16;
			i++;
		}
		return (i);
	}
	return (0);
}
