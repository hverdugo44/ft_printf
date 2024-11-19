/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hverdugo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:17:57 by hverdugo          #+#    #+#             */
/*   Updated: 2024/10/27 13:21:59 by hverdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexadecimal(unsigned long hex, int *x)
{
	if (hex < 16)
	{
		if (hex < 10)
			ft_prntchar(hex + '0');
		else
			ft_prntchar(hex - 10 + 'a');
	}
	else
	{
		hexadecimal(hex / 16, x);
		hexadecimal(hex % 16, x);
		*x += 1;
	}
}
