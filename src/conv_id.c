/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:04:28 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/16 16:10:24 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_conv_id1(t_flag modif, int len, int nb, int k)
{
	int i;

	i = -1;
	if (modif.preci == -1 ||
	(modif.width > len && modif.preci >= len))
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
	if (modif.preci < len && modif.preci != -1)
	{
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
		while (++i < modif.width - len)
			ft_putchar(' ');
	}
	else if ((nb < 0 && modif.preci == -1) || nb >= 0)
		while (++i < modif.width - k)
			ft_putchar(' ');
	else
		while (++i < modif.width - k - 1)
			ft_putchar(' ');
}

static void	ft_conv_id0(t_flag modif, int nb, int k)
{
	int i;

	i = -1;
	if (modif.preci < ft_lgth(nb) && modif.preci != -1)
	{
		while (++i < modif.width - ft_lgth(nb))
			ft_putchar(' ');
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
	}
	else if ((nb < 0 && modif.preci == -1) || nb >= 0)
		while (++i < modif.width - k)
			ft_putchar(' ');
	else
		while (++i < modif.width - k - 1)
			ft_putchar(' ');
	if ((modif.preci == -1) ||
		(modif.width > ft_lgth(nb) && modif.preci >= ft_lgth(nb)))
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
}

static void	ft_conv_id2(t_flag modif, int nb, int k)
{
	int i;

	i = -1;
	if (modif.preci < ft_lgth(nb) && modif.preci != -1)
	{
		while (++i < modif.width - ft_lgth(nb))
			ft_putchar(' ');
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
	}
	else if ((nb < 0 && modif.preci == -1 && modif.zero == 0) ||
		(nb >= 0 && modif.preci != -1))
		while (++i < modif.width - k)
			ft_putchar(' ');
	else if (modif.width > modif.preci && modif.preci != -1)
		while (++i < modif.width - k - 1)
			ft_putchar(' ');
	if ((modif.preci == -1) ||
		(modif.width > ft_lgth(nb) && modif.preci >= ft_lgth(nb)))
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
}

void		ft_conv_bis(t_flag modif, va_list args, int nb, int k)
{
	if (modif.minus == 1)
		ft_conv_id1(modif, ft_lgth(nb), nb, k);
	if (modif.minus == 0 && modif.zero == 0)
		ft_conv_id0(modif, nb, k);
	if (modif.minus == 0 && modif.zero == 1)
		ft_conv_id2(modif, nb, k);
	if (modif.preci >= ft_lgth(nb) && modif.width <= ft_lgth(nb))
		ft_putnbr(nb, modif.preci, ft_lgth(nb), modif);
	modif.length += k > modif.width ? k : modif.width;
	if (modif.preci >= modif.width && nb < 0 && modif.preci >= ft_lgth(nb))
		modif.length++;
}

t_flag		ft_conv_id(t_flag modif, va_list args)
{
	int nb;
	int i;
	int k;

	i = -1;
	nb = va_arg(args, int);
	k = modif.preci >= ft_lgth(nb) ? modif.preci : ft_lgth(nb);
	if (nb == 0 && modif.preci == 0)
	{
		while (++i < modif.width)
			ft_putchar(' ');
		modif.length += modif.width;
		return (modif);
	}
	ft_conv_bis(modif, args, nb, k);
	return (modif);
}
