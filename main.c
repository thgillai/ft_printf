/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:45:32 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/20 13:26:06 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	main(void)
{
	int i = 123;
	int x = 123;
	unsigned int u = 123;
	char c = 68;
	char *s = "Hello World!";
	

	printf("\033[38;5;46mPercent test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"%-0*%/\n", 5);
	ft_printf("\033[1;33mft_printf:\033[0m"			"%-0*%/\n\n", 5);

	printf("\033[38;5;46mChar test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"%*c/\n", 5,c);
	ft_printf("\033[1;33mft_printf:\033[0m"			"%*c/\n\n", 5,c);

	printf("\033[38;5;46mString test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"%-*.*s/\n", 9, 5, s);
	ft_printf("\033[1;33mft_printf:\033[0m"			"%-*.*s/\n\n", 9, 5, s);

	printf("\033[38;5;46mDigit i test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"%*.*i/\n", 5, 1, i);
	ft_printf("\033[1;33mft_printf:\033[0m"			"%*.*i/\n\n", 5, 1, i);

	printf("\033[38;5;46mDigit d test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"%*.*d/\n", 5, 1, i);
	ft_printf("\033[1;33mft_printf:\033[0m"			"%*.*d/\n\n", 5, 1, i);

	printf("\033[38;5;46mPointer test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"-->|%-16p|<--\n", s);
	ft_printf("\033[1;33mft_printf:\033[0m"			"-->|%-16p|<--\n\n", s);

	printf("\033[38;5;46mUnsigned test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"%*.*u/\n", 5, 1, u);
	ft_printf("\033[1;33mft_printf:\033[0m"			"%*.*u/\n\n", 5, 1, u);

	printf("\033[38;5;46mHexa test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"%*.*x/\n", 5, 1, x);
	ft_printf("\033[1;33mft_printf:\033[0m"			"%*.*x/\n\n", 5, 1, x);

	printf("\033[38;5;46mHEXA test\033[0m\n");
	printf("\033[1;33mprintf   :\033[0m"			"%*.*X/\n", 5, 1, x);
	ft_printf("\033[1;33mft_printf:\033[0m"			"%*.*X/\n\n", 5, 1, x);

	return (0);
}
