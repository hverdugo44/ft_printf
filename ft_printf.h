/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:11:37 by hverdugo          #+#    #+#             */
/*   Updated: 2024/10/27 13:22:21 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		hexa(unsigned int hex, char c);
int		ft_prntchar(int c);
int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		format(va_list formato, char *str);
int		ft_putnbr(int n);
char	*relleno(char *str, int *prnt);
void	hexadecimal(unsigned long hex, int *x);
void	hexadecimalxm(unsigned int hex, int *x);
int		puntero(unsigned long i);
void	ft_uint(unsigned int n, int *x);

#endif
