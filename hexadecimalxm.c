/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimalxm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:19:02 by hverdugo          #+#    #+#             */
/*   Updated: 2024/10/27 13:11:51 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexadecimalxm(unsigned int hex, int *x)
{
	if (hex < 16)
	{
		if (hex < 10)
			x += ft_prntchar(hex + '0');
		else
			x += ft_prntchar(hex - 10 + 'A');
	}
	else
	{
		hexadecimalxm(hex / 16, x);
		hexadecimalxm(hex % 16, x);
		*x += 1;
	}
}
