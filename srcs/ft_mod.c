/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:56:51 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/28 13:32:09 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

const char	*ft_mod(va_list arg, const char *fmt, t_print *src)
{
	int				d;
	char			*s;
	unsigned int	x;

	if (*fmt == 'd' || *fmt == 'i')
	{
		d = va_arg(arg, int);
		ft_putnbr(d);
		src->len += ft_intlen(d, *fmt);
	}
	else if (*fmt == 'u')
	{
		d = va_arg(arg, int);
		ft_putnbr_u(d);
		src->len += ft_intlen_u(d, *fmt);
	}
	else if (*fmt == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
		{
			write(1, "(null)", 6);
			src->len += 6;
		}
		else
		{
			ft_putstr(s);
			src->len += ft_strlen(s);
		}
	}
	else if (*fmt == 'x')
	{
		x = va_arg(arg, unsigned int);
		ft_phex((unsigned long)x);
		src->len += ft_intlen((unsigned long)x, *fmt);
	}
	else
		return (NULL);
	fmt++;
	return (fmt);
}
