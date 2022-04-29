/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:36:18 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/29 13:16:16 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	int	res = ft_printf("FakePrintf %p\n", LONG_MIN);
	int	resA = ft_printf("FakePrintf %p\n", ULONG_MAX);
	int	res2 = printf("RealPrintf %p\n", LONG_MIN);
	int	res3 = printf("RealPrintf %p\n", ULONG_MAX);

	printf("\nres = %d\nresA = %d\nres2 = %d\nres3 = %d\n", res, resA, res2, res3);
	return (0);
}
