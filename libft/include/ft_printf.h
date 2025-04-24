/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:29 by doberes           #+#    #+#             */
/*   Updated: 2025/01/10 09:37:34 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ============================================================================
// ------------------------ Create static library -----------------------------
// ============================================================================
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// ============================================================================
// -------------------------- Included libraries ------------------------------
// ============================================================================

// printf()
# include <stdio.h>

// va_list, va_arg, va_start, va_copy, va_end
# include <stdarg.h>

// write()
# include <unistd.h>

// malloc(), free(), size_t
# include <stdlib.h>

// ============================================================================
// -------------------------- Included fonctions ------------------------------
// ============================================================================

// ----------------------------- Main fonction --------------------------------
int	ft_printf(const char *format, ...);

// ------------------------ Non-static sub fonctions --------------------------
int	check_format(char specifier, va_list arg_ptr);
int	print_char(int c);
int	print_string(char *str);
int	print_number(long n);
int	print_hex(unsigned long long nbr, const char *symbols);
int	print_pointer(void *ptr);
int	print_unsigned(unsigned int n);

#endif