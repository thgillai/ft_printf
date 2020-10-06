/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:23:24 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/02 13:45:38 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_len(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		ft_putchar(s[i]);
}

void	ft_putnstr(char *s, int n)
{
	int i;

	i = -1;
	if (!s)
		return ;
	while (s[++i] && i < n)
		ft_putchar(s[i]);
}

int		ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
