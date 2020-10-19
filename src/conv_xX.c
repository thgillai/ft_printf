/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:47:59 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/19 13:17:37 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			ft_conv1_x(t_flag modif, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (modif.preci == -1 ||
	(modif.width >= ft_16(nb) && modif.preci >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), modif);
	if (modif.preci < ft_16(nb) && modif.preci != -1)
	{
		ft_putnbr_base(nb, base, ft_16(nb), modif);
		while (++i < modif.width - ft_16(nb))
			ft_putchar(' ');
	}
	else
		while (++i < modif.width - k)
			ft_putchar(' ');
}

static void			ft_conv0_x(t_flag modif, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (modif.preci < ft_16(nb) && modif.preci != -1)
	{
		while (++i < modif.width - ft_16(nb))
			ft_putchar(' ');
		ft_putnbr_base(nb, base, ft_16(nb), modif);
	}
	else
		while (++i < modif.width - k)
			ft_putchar(' ');
	if ((modif.preci == -1) ||
		(modif.width >= ft_16(nb) && modif.preci >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), modif);
}

static void			ft_conv2_x(t_flag modif, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (modif.preci < ft_16(nb) && modif.preci != -1)
	{
		while (++i < modif.width - ft_16(nb))
			ft_putchar(' ');
		ft_putnbr_base(nb, base, ft_16(nb), modif);
	}
	else if (modif.preci != -1)
		while (++i < modif.width - k)
			ft_putchar(' ');
	else if (modif.width > modif.preci && modif.preci != -1)
		while (++i < modif.width - k - 1)
			ft_putchar(' ');
	if ((modif.preci == -1) ||
		(modif.width >= ft_16(nb) && modif.preci >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), modif);
}

static	void		ft_25_lignes(t_flag modif)
{
	int i;

	i = -1;
	while (++i < modif.width)
		ft_putchar(' ');
}

t_flag				ft_conv_x(t_flag modif, va_list args, char c)
{
	long	nb;
	int		k;
	char	*base;

	base = c == 120 ? "0123456789abcdef" : "0123456789ABCDEF";
	nb = va_arg(args, unsigned int);
	k = modif.preci >= ft_16(nb) ? modif.preci : ft_16(nb);
	if (nb == 0 && modif.preci == 0)
	{
		ft_25_lignes(modif);
		modif.length += modif.width;
		return (modif);
	}
	if (modif.minus == 1)
		ft_conv1_x(modif, nb, k, base);
	if (modif.minus == 0 && modif.zero == 0)
		ft_conv0_x(modif, nb, k, base);
	if (modif.minus == 0 && modif.zero == 1)
		ft_conv2_x(modif, nb, k, base);
	if (modif.preci >= ft_16(nb) && modif.width < ft_16(nb))
		ft_putnbr_base(nb, base, ft_16(nb), modif);
	modif.length += k > modif.width ? k : modif.width;
	return (modif);
}
