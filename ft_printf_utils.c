/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:16:37 by hverdugo          #+#    #+#             */
/*   Updated: 2024/10/24 16:26:23 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*str;
	int		x;

	str = ft_itoa(n);
	x = write(1, str, ft_strlen(str));
	free(str);
	return (x);
}

int	ft_prntchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x] != 0)
		x += write(1, &str[x], 1);
	return (x);
}

void	ft_uint(unsigned int n, int *x)
{
	if (n < 10)
		*x += ft_prntchar(n + 48);
	else
	{
		ft_uint(n / 10, x);
		ft_uint(n % 10, x);
	}
}
