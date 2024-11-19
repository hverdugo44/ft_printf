/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:52:50 by hverdugo          #+#    #+#             */
/*   Updated: 2024/10/27 13:20:59 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(va_list formato, char *str)
{
	char	*tem;
	int		x;

	x = 0;
	if (*str == 'c')
		return (ft_prntchar(va_arg(formato, int)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(formato, int)));
	else if (*str == '%')
		return (ft_prntchar('%'));
	else if (*str == 's')
	{
		tem = va_arg(formato, char *);
		if (tem == NULL)
			return (ft_putstr("(null)"));
		return (ft_putstr(tem));
	}
	else if (*str == 'x' || *str == 'X')
		return (hexa(va_arg(formato, unsigned int), str[0]));
	else if (*str == 'p')
		return (puntero(va_arg(formato, unsigned long )));
	else if (*str == 'u')
		ft_uint(va_arg(formato, unsigned int), &x);
	return (x);
}

int	hexa(unsigned int hex, char c)
{
	int	x;

	x = 1;
	if (hex == 0)
		return (write(1, "0", 1));
	else if (c == 'x')
		hexadecimal(hex, &x);
	else if (c == 'X')
		hexadecimalxm(hex, &x);
	return (x);
}

int	ft_printf(const char *str, ...)
{
	int			prnt;
	va_list		formato;
	int			x;

	x = 0;
	prnt = 0;
	va_start(formato, str);
	while (str[x])
	{
		if (str[x] != 0 && str[x] != '%')
			prnt += write(1, &str[x], 1);
		else
		{
			if (!str[x])
				break ;
			else
			{
				x++;
				prnt += format(formato, (char *)&str[x]);
			}
		}
		x++;
	}
	va_end(formato);
	return (prnt);
}
