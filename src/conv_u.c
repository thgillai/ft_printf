/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:47:33 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/02 13:47:38 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			ft_conv_u1(t_flag modif, int len, unsigned int nb, int k)
{
	int i;

	i = -1;
	if (modif.preci == -1 ||
	(modif.width >= len && modif.preci >= len))
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
	if (modif.preci < len && modif.preci != -1)
	{
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
		while (++i < modif.width - len)
			ft_putchar(' ');
	}
	else
		while (++i < modif.width - k)
			ft_putchar(' ');
}

static void			ft_conv_u0(t_flag modif, unsigned int nb, int k)
{
	int i;

	i = -1;
	if (modif.preci < ft_lgth(nb) && modif.preci != -1)
	{
		while (++i < modif.width - ft_lgth(nb))
			ft_putchar(' ');
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
	}
	else
		while (++i < modif.width - k)
			ft_putchar(' ');
	if ((modif.preci == -1) ||
		(modif.width >= ft_lgth(nb) && modif.preci >= ft_lgth(nb)))
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
}

static void			ft_conv_u2(t_flag modif, unsigned int nb, int k)
{
	int i;

	i = -1;
	if (modif.preci < ft_lgth(nb) && modif.preci != -1)
	{
		while (++i < modif.width - ft_lgth(nb))
			ft_putchar(' ');
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
	}
	else if (modif.preci != -1)
		while (++i < modif.width - k)
			ft_putchar(' ');
	else if (modif.width > modif.preci && modif.preci != -1)
		while (++i < modif.width - k - 1)
			ft_putchar(' ');
	if ((modif.preci == -1) ||
		(modif.width >= ft_lgth(nb) && modif.preci >= ft_lgth(nb)))
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
}

t_flag				ft_conv_u(t_flag modif, va_list argp)
{
	unsigned int	nb;
	int				i;
	int				k;

	i = -1;
	nb = va_arg(argp, unsigned int);
	k = modif.preci >= ft_lgth(nb) ? modif.preci : ft_lgth(nb);
	if (nb == 0 && modif.preci == 0)
	{
		while (++i < modif.width)
			ft_putchar(' ');
		modif.length += modif.width;
		return (modif);
	}
	if (modif.minus == 1)
		ft_conv_u1(modif, ft_lgth(nb), nb, k);
	if (modif.minus == 0 && modif.zero == 0)
		ft_conv_u0(modif, nb, k);
	if (modif.minus == 0 && modif.zero == 1)
		ft_conv_u2(modif, nb, k);
	if (modif.preci >= ft_lgth(nb) && modif.width < ft_lgth(nb))
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
	modif.length += k > modif.width ? k : modif.width;
	return (modif);
}
