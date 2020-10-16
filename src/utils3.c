/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:55:33 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/16 16:07:57 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_atoi(char *str)
{
	int				i;
	unsigned long	result;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > LONG_MAX)
		return (0);
	return (result);
}

int	ft_lgth(long int nb)
{
	if (nb < 0)
		return (1 + ft_lgth(nb * (-1)));
	if (nb > 9)
		return (1 + ft_lgth(nb / 10));
	return (1);
}
