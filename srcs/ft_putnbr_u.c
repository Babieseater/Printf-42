/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:51:36 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/28 13:32:28 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putnbr_u(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr_u(nb / 10);
	ft_putchar('0' + nb % 10);
}
