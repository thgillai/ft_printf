/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:36:32 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/06 17:04:42 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		ft_putnbr(long long nb, int preci, int len, t_flag modif)
{
	long int	nbr;
	long int	mod;
	long int	div;

	nbr = nb;
	if (preci == -1 && modif.width)
		preci = nbr >= 0 ? modif.width : modif.width - 1;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
		len--;
	}
	if (modif.preci != -1 ||
		(modif.preci == -1 && modif.width > ft_lgth(nb) && modif.zero))
		while (preci > len)
		{
			ft_putchar('0');
			preci--;
		}
	mod = nbr % 10;
	div = nbr / 10;
	if (div)
		ft_putnbr(div, preci, len, modif);
	ft_putchar(mod + 48);
}

int			ft_16(unsigned long int nb)
{
	if (nb > 15)
		return (1 + ft_16(nb / 16));
	return (1);
}

void		ft_putnbr_base(unsigned long nbr, char *base, int len, t_flag modif)
{
	long long int	div;
	long long int	mod;

	if (modif.preci != -1)
		while (modif.preci > len)
		{
			ft_putchar('0');
			modif.preci--;
		}
	if (modif.preci == -1 && modif.width >= ft_16(nbr) && modif.zero)
		while (modif.width > len)
		{
			ft_putchar('0');
			modif.width--;
		}
	mod = nbr % 16;
	div = nbr / 16;
	if (div)
		ft_putnbr_base(div, base, len, modif);
	ft_putchar(base[mod]);
}

t_flag		ft_verif(t_flag modif)
{
	if (modif.width < 0)
	{
		modif.width *= -1;
		modif.minus = 1;
		modif.zero = 0;
	}
	if (modif.preci < 0)
		modif.preci = -1;
	return (modif);
}

t_flag		ft_len_s(t_flag modif, char *str)
{
	if (modif.preci == -1 && modif.width > 0 && str)
		modif.length += modif.width > ft_len(str) ? modif.width : ft_len(str);
	if (modif.width == 0 && modif.preci != -1 && str)
		modif.length += modif.preci > ft_len(str) ? ft_len(str) : modif.preci;
	if (modif.preci != -1 && modif.width > 0 && str)
	{
		if (modif.preci > modif.width && modif.preci >= ft_len(str))
			modif.length += modif.width < ft_len(str) ? ft_len(str) : modif.width;
		else if (modif.preci > modif.width && modif.preci < ft_len(str))
			modif.length += modif.width < ft_len(str) ? modif.preci : modif.width;
		else
			modif.length += modif.width;
	}
	if (modif.width == 0 && modif.preci == -1 && str)
		modif.length += ft_len(str);
	if (!str)
		modif.length += modif.width;
	return (modif);
}
