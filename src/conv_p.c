/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:47:42 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/20 13:42:48 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_conv_p2(t_flag modif, int i, unsigned long int nb)
{
	while (++i < modif.width - ft_16(nb) - 2)
		ft_putchar(' ');
	write(1, "0x", 2);
}

void	ft_conv_p1(t_flag modif, int i, unsigned long int nb, char *base)
{
	if (modif.width - 1 < ft_16(nb))
	{
		write(1, "0x", 2);
		ft_putnbr_base(nb, base, ft_16(nb), modif);
	}
	if (modif.width > ft_16(nb) && modif.minus == 0)
	{
		ft_conv_p2(modif, i, nb);
		ft_putnbr_base(nb, base, ft_16(nb), modif);
	}
	else if (modif.minus == 1 && modif.width > ft_16(nb))
	{
		write(1, "0x", 2);
		ft_putnbr_base(nb, base, ft_16(nb), modif);
		while (++i < modif.width - ft_16(nb) - 2)
			ft_putchar(' ');
	}
}

t_flag	ft_conv_p(t_flag modif, va_list args)
{
	int					i;
	unsigned long int	nb;
	char				*base;

	i = -1;
	base = "0123456789abcdef";
	nb = va_arg(args, long);
	if (nb == 0 && modif.preci == 0)
	{
		ft_putstr("0x");
		modif.length += 2;
		return (modif);
	}
	ft_conv_p1(modif, i, nb, base);
	modif.length += modif.width > ft_16(nb) ? modif.width : ft_16(nb) + 2;
	modif.length += modif.width == ft_16(nb) + 1 ? 1 : 0;
	return (modif);
}
