/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:36:18 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/28 15:32:43 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	int	res = ft_printf("FakePrintf %c\n", 'z');
	int	resA = ft_printf("FakePrintf %c\n", 'w', '1');
	int	res2 = printf("RealPrintf %c\n", 'z');
	int	res3 = printf("RealPrintf %c\n", 'w', '1');

	printf("\nres = %d\nresA = %d\nres2 = %d\nres3 = %d\n", res, resA, res2, res3);
	return (0);
}
