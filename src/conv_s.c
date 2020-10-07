/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:47:18 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/07 12:33:35 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_conv_s1(t_flag modif, char *str)
{
	int i;

	i = -1;
	if (modif.preci == -1 ||
		(modif.width > ft_len(str) && modif.preci >= ft_len(str)))
		ft_putstr(str);
	if (modif.preci < ft_len(str) && modif.preci != -1)
	{
		ft_putnstr(str, modif.preci);
		while (++i < modif.width - modif.preci)
			ft_putchar(' ');
	}
	else
	{
		while (++i < modif.width - ft_len(str))
			ft_putchar(' ');
	}
}

void	ft_conv_s0(t_flag modif, char *str)
{
	int i;

	i = -1;
	if (modif.preci < ft_len(str) && modif.preci != -1)
	{
		while (++i < modif.width - modif.preci)
			ft_putchar(' ');
		ft_putnstr(str, modif.preci);
	}
	else
	{
		while (++i < modif.width - ft_len(str))
			ft_putchar(' ');
	}
	if ((modif.preci == -1) ||
		(modif.width > ft_len(str) && modif.preci >= ft_len(str)))
		ft_putstr(str);
}

t_flag	ft_conv_s(t_flag modif, va_list argp)
{
	char	*str;

	str = va_arg(argp, void *);
	if (!str)
		str = "(null)";
	if (modif.minus == 1 && str)
		ft_conv_s1(modif, str);
	if (modif.minus == 0 && str)
		ft_conv_s0(modif, str);
	if (modif.preci >= ft_len(str) && modif.width <= ft_len(str))
		ft_putstr(str);
	modif = ft_len_s(modif, str);
	return (modif);
}
