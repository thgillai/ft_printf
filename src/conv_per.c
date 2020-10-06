/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_per.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:49:33 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/06 17:19:31 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_flag	ft_conv_per(t_flag modif)
{
	int i;

	i = -1;
	if (modif.width <= 1)
		ft_putchar('%');
	if (modif.minus == 0 && modif.width > 1)
	{
		while (++i < modif.width - 1)
			modif.zero == 0 ? ft_putchar(' ') : ft_putchar('0');
		ft_putchar('%');
	}
	else if (modif.minus == 1 && modif.width > 1)
	{
		ft_putchar('%');
		while (++i < modif.width - 1)
			modif.zero == 0 ? ft_putchar(' ') : ft_putchar('0');
	}
	modif.length += modif.width == 0 ? 1 : modif.width;
	return (modif);
}
