/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:32:40 by doberes           #+#    #+#             */
/*   Updated: 2025/03/04 11:41:28 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ============================================================================
// -------------------------- Included libraries ------------------------------
// ============================================================================

#include "ft_printf.h"

// ============================================================================
// ----------------------------- check_format ---------------------------------
// ============================================================================
// checks the char after the specifier '%' and calls the print sub-fonction

int	check_format(char specifier, va_list arg_ptr)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(arg_ptr, int));
	else if (specifier == 's')
		count += print_string(va_arg(arg_ptr, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_number(va_arg(arg_ptr, int));
	else if (specifier == 'x')
		count += print_hex(va_arg(arg_ptr, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		count += print_hex(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF");
	else if (specifier == 'p')
		count += print_pointer(va_arg(arg_ptr, void *));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(arg_ptr, unsigned int));
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &specifier, 1);
	return (count);
}
