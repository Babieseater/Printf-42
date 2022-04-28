/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:11:33 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/28 13:32:19 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_phex(unsigned int x)
{
	char	*hex;
	int		result[100];
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (x >= 16)
	{
		result[i] = hex[x % 16];
		x = x / 16;
		i++;
	}
	result[i] = hex[x];
	while (i >= 0)
	{
		ft_putchar(result[i]);
		i--;
	}
}
