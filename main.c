/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:36:18 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/28 13:37:56 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	int	res = ft_printf("FakePrintf %i\n", 33333333333);
	int	resA = ft_printf("FakePrintf %d\n", -55555555555);
	int	res2 = printf("RealPrintf %i\n", 33333333333);
	int	res3 = printf("RealPrintf %d\n", -55555555555);

	printf("\nres = %d\nresA = %d\nres2 = %d\nres3 = %d\n", res, resA, res2, res3);
	return (0);
}
