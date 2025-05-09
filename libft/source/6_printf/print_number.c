/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:52:20 by doberes           #+#    #+#             */
/*   Updated: 2025/01/06 16:33:10 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prints a decimal base number ASCII char by ASCII char

// ============================================================================
// -------------------------- Included libraries ------------------------------
// ============================================================================

#include "ft_printf.h"

// ============================================================================
// ----------------------------- print_number ---------------------------------
// ============================================================================

int	print_number(long n)
{
	int			count;
	const char	*symbols;

	count = 0;
	symbols = "0123456789";
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
		count += print_char(symbols[n]);
	else
	{
		count += print_number(n / 10);
		count += print_number(n % 10);
	}
	return (count);
}
