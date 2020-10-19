/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 13:30:20 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/19 13:17:18 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_flag		ft_analyzer(const char *s, t_flag modif, va_list args)
{
	if (s[modif.i] == '%' && s[modif.i + 1])
		modif = ft_set_flag((char *)s, modif, args);
	if (s[modif.i] == '%')
		modif = ft_conv_per(modif);
	if (s[modif.i] == 'c')
		modif = ft_conv_c(modif, args);
	if (s[modif.i] == 's')
		modif = ft_conv_s(modif, args);
	if (s[modif.i] == 'd' || s[modif.i] == 'i')
		modif = ft_conv_id(modif, args);
	if (s[modif.i] == 'u')
		modif = ft_conv_u(modif, args);
	if (s[modif.i] == 'x' || s[modif.i] == 'X')
		modif = ft_conv_x(modif, args, s[modif.i]);
	if (s[modif.i] == 'p')
		modif = ft_conv_p(modif, args);
	modif.minus = 0;
	modif.zero = 0;
	modif.width = 0;
	modif.preci = -1;
	return (modif);
}

t_flag		ft_set_flag(char *s, t_flag modif, va_list args)
{
	while (s[++modif.i] == '-' || s[modif.i] == '0')
	{
		if (s[modif.i] == '-')
			modif.minus = 1;
		if (s[modif.i] == '0')
			modif.zero = 1;
	}
	if (modif.minus == 1)
		modif.zero = 0;
	modif.width = s[modif.i] == '*' ? va_arg(args, int) : ft_atoi(s + modif.i);
	while ((s[modif.i] >= '0' && s[modif.i] <= '9') || s[modif.i] == '*')
		modif.i++;
	if (s[modif.i] == '.')
		modif.preci = s[modif.i + 1] == '*' ? va_arg(args, int) :
	ft_atoi(s + modif.i + 1);
	modif = ft_verif(modif);
	while (ft_isdigit(s[modif.i]) || s[modif.i] == '*' || s[modif.i] == '.')
		modif.i++;
	return (modif);
}

t_flag		ft_initialize(void)
{
	t_flag modif;

	modif.minus = 0;
	modif.zero = 0;
	modif.width = 0;
	modif.preci = -1;
	modif.i = 0;
	modif.length = 0;
	return (modif);
}

int			ft_printf(const char *s, ...)
{
	va_list args;
	t_flag	modif;

	va_start(args, s);
	modif = ft_initialize();
	while (s[modif.i])
	{
		while (s[modif.i] && s[modif.i] != '%')
		{
			ft_putchar(s[modif.i++]);
			modif.length++;
		}
		if (s[modif.i] == '%')
			modif = ft_analyzer(s, modif, args);
		if (s[modif.i] == 0)
			break ;
		modif.i++;
	}
	va_end(args);
	return (modif.length);
}
