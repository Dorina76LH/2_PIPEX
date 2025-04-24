/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:28:47 by doberes           #+#    #+#             */
/*   Updated: 2025/01/06 16:33:10 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ============================================================================
// -------------------------- Included libraries ------------------------------
// ============================================================================

#include "ft_printf.h"

// ============================================================================
// -------------------------------- print_hex ---------------------------------
// ============================================================================

// coverts a decimal base number in hexadecimal (uppercase or lowercase format)

int	print_hex(unsigned long long nbr, const char *symbols)
{
	int	count;

	count = 0;
	if (nbr < 16)
		count += print_char(symbols[nbr]);
	else
	{
		count += print_hex(nbr / 16, symbols);
		count += print_hex(nbr % 16, symbols);
	}
	return (count);
}

// int	print_number_base(unsigned int nbr, const char *symbols, int base)
// {
// 	int	count;

// 	count = 0;
// 	if (nbr < (unsigned int)base)
// 		count += print_char(symbols[nbr]);
// 	else
// 	{
// 		count += print_number_base(nbr / base, symbols, base);
// 		count += print_number_base(nbr % base, symbols, base);
// 	}
// 	return (count);
// }
