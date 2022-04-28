/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:45:36 by smayrand          #+#    #+#             */
/*   Updated: 2022/04/28 11:42:11 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_print
{
	unsigned int	len;
	unsigned int	width;
}		t_print;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_modchr(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char *)s);
		s++;
	}
	if (!s)
		return ((char *)s);
	return (NULL);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10);
	ft_putchar('0' + nb % 10);
}

int	ft_intlen(long int nb, char z)
{
	long int	i;
	long int	nbr;
	int			nega;

	i = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		nega = 1;
		nbr = -nb * 10;
	}
	else
	{
		nega = 0;
		nbr = nb;
	}
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

//les unsigned int sont necessaire pour les nombres au dessus de 3.2b dans %u
int	ft_intlen_u(unsigned int nb, char z)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	if (!nb)
		return (1);
	nbr = nb;
	if (z == 'u')
	{
		while (nbr)
		{
			nbr /= 10;
			i++;
		}
		return (i);
	}
	return (0);
}

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
		ft_putnbr_unsigned(d);
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

const char	*ft_read(t_print *src, const char *fmt)
{
	char	*next;

	next = ft_modchr(fmt);
	if (next)
		src->width = next - fmt;
		//next - format puisqu'on veut juste la taille de next
	else
		src->width = ft_strlen(fmt);
	write(1, fmt, src->width);
	src->len += src->width;
	while (*fmt && *fmt != '%')
		fmt++;
	return (fmt);
}

int	ft_printf(const char *fmt, ...)
{
	t_print	src;
	va_list	arg;

	va_start(arg, fmt);
	src.len = 0;
	src.width = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			fmt = ft_mod(arg, fmt + 1, &src);
		else
			fmt = ft_read(&src, fmt);
		if (!fmt)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (src.len);
		}
	}
	va_end(arg);
	return (src.len);
}

int	main()
{
	int	res = ft_printf("FakePrintf %u\n", 33333333333);
	int	resA = ft_printf("FakePrintf %x\n", "0r3");
	int	res2 = printf("RealPrintf %u\n", 33333333333);
	int	res3 = printf("RealPrintf %x\n", "0r3");

	printf("\nres = %d\nresA = %d\nres2 = %d\nres3 = %d\n", res, resA, res2, res3);
	return (0);
}