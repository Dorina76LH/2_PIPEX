/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:00:23 by doberes           #+#    #+#             */
/*   Updated: 2025/01/06 16:33:10 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ============================================================================
// -------------------------- Included libraries ------------------------------
// ============================================================================

#include "ft_printf.h"

// ============================================================================
// ---------------------------- print_pointer ---------------------------------
// ============================================================================

// - converts the address of the pointer in an unsigned long
// - print '0x' specifier for pointer address
// - print the pointer address in hexadecimal (lowercase) format
// - return : number of printed chars

int	print_pointer(void *ptr)
{
	unsigned long long	address;
	int					count;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	address = (unsigned long long)ptr;
	count += write(1, "0x", 2);
	count += print_hex(address, "0123456789abcdef");
	return (count);
}
