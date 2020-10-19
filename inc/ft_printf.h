/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 13:31:03 by thgillai          #+#    #+#             */
/*   Updated: 2020/10/19 13:16:30 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_flag
{
	int	minus;
	int	zero;
	int	width;
	int	preci;
	int	preca;
	int	i;
	int	length;
}				t_flag;

int				ft_printf(const char *s, ...);
t_flag			ft_analyzer(const char *s, t_flag modif, va_list args);
t_flag			ft_initialize(void);
t_flag			ft_set_flag(char *s, t_flag modif, va_list args);
t_flag			ft_conv_s(t_flag modif, va_list args);
t_flag			ft_conv_c(t_flag modif, va_list args);
t_flag			ft_conv_id(t_flag modif, va_list args);
t_flag			ft_len_s(t_flag modif, char *str);
t_flag			ft_conv_x(t_flag modif, va_list args, char c);
t_flag			ft_conv_u(t_flag modif, va_list args);
t_flag			ft_conv_p(t_flag modif, va_list args);
t_flag			bis(t_flag modif, va_list args, int i,
					unsigned long int nb, char *base);
t_flag			ft_conv_per(t_flag modif);
t_flag			ft_verif(t_flag modif);
int				ft_16(unsigned long int nb);
void			ft_putnbr_base(unsigned long nb,
				char *base, int len, t_flag modif);
void			ft_putnbr(long long nb, int prec, int len, t_flag modif);
int				ft_len(char *s);
int				ft_atoi(char *s);
int				ft_isdigit(char c);
int				ft_lgth(long int nb);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnstr(char *s, int n);

#endif
