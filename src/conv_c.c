/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:02:46 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/06 16:51:55 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_flag	ft_conv_c(t_flag modif, va_list args)
{
	int i;

	i = -1;
	if (modif.width == 1)
		ft_putchar(va_arg(args, int));
	if (modif.minus == 0 && modif.width != 1)
	{
		while (++i < modif.width - 1)
			ft_putchar(' ');
		ft_putchar(va_arg(args, int));
	}
	else if (modif.minus == 1 && modif.width != 1)
	{
		ft_putchar(va_arg(args, int));
		while (++i < modif.width - 1)
			ft_putchar(' ');
	}
	modif.length += modif.width == 0 ? 1 : modif.width;
	return (modif);
}