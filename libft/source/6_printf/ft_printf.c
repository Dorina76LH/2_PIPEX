/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:32:40 by doberes           #+#    #+#             */
/*   Updated: 2025/01/06 16:33:10 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ============================================================================
// -------------------------- Included libraries ------------------------------
// ============================================================================

#include "ft_printf.h"

// ============================================================================
// ------------------------------ ft_printf -----------------------------------
// ============================================================================
// Receives a string and a variable number of arguments as parameters
// - count : number of printed chars
// - va_list : initialise va_list
// - va_start : position of first argument
// - loop : call check_format if '%' format specifier found
// - va_end : clean va_list (delete data and free malloc)
// - return : count

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		count;

	va_start(arg_ptr, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			count += check_format(*format, arg_ptr);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(arg_ptr);
	return (count);
}

// // =========================================================================
// // -------------------------- Included libraries ---------------------------
// // =========================================================================
// #include "ft_printf.h"
// // =========================================================================
// // --------------------------------- main ----------------------------------
// // =========================================================================
// // create main.c
// // gcc -Wall -Wextra -Werror -Iincludes main.c -L. -lftprintf -o test
// // -Include : .h files
// // -L : folder of libftprintf.a
// // -lftprintf : include the library libftprintf.a
// // -o test : name of .o 'test'
// // ./test : run 'test'
// // main fonction => compare ft_printf and printf fonctions
// int	main(void)
// {
// 	int		count;
// 	int		x;
// 	void	*ptr;
// 	x = 42;
// 	ptr = &x;
// 	count = 0;
// 	// -------- test %c --------
// 	printf("\n\n---- Test char ----\n");
// 	count = ft_printf("ft_printf >> %c | ", 'A');
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %c | ", 'A');
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %c%c | ", 'A', 'B');
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %c%c | ", 'A', 'B');
// 	printf("Printed chars : %d\n", count);
// 	//
// 	// -------- test %s --------
// 	printf("\n\n---- Test string ----\n");
// 	count = ft_printf("ft_printf >> Hello %s ! | ", "World");
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> Hello %s ! | ", "World");
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> Hello %s ! | ", "");
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> Hello %s ! | ", "");
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %s%s", "Hello ", "World ! | ");
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %s%s", "Hello ", "World ! | ");
// 	printf("Printed chars : %d\n", count);
// 	//
// 	// -------- test %d --------
// 	printf("\n\n---- Test %%d ----\n");
// 	count = ft_printf("ft_printf >> %d | ", 0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %d | ", 0);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %d | ", 42);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %d | ", 42);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %d | ", 2147483647);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %d | ", 2147483647);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %d | ", -7000);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %d | ", -7000);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %d | ", -2147483648);
// 	ft_printf("Printed chars : %d\n", count);
// 	//count = printf("   printf >> %d | ", -2147483648);
// 	//printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %d%d | ", -7000, 42);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %d%d | ", -7000, 42);
// 	printf("Printed chars : %d\n", count);
// 	//
// 	// -------- test %% --------
// 	printf("\n\n---- Test %% ----\n");
// 	count = ft_printf("ft_printf >> %% test | ");
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %% test | ");
// 	printf("Printed chars : %d\n", count);
// 	//
// 	// -------- test hexa lower --------
// 	printf("\n\n---- Test hexa lower ----\n");
// 	count = ft_printf("ft_printf >> %x | ", -2400);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %x | ", -2400);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %x | ", -1);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %x | ", -1);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %x | ", 0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %x | ", 0);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %x | ", 42);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %x | ", 42);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %x%x | ", 42,0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %x%x | ", 42, 0);
// 	printf("Printed chars : %d\n", count);
// 	//
// 	// -------- test hexa upper --------
// 	printf("\n\n---- Test hexa upper ----\n");
// 	count = ft_printf("ft_printf >> %X | ", -2400);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %X | ", -2400);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %X | ", -1);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %X | ", -1);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %X | ", 0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %X | ", 0);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %X | ", 42);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %X | ", 42);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %X%X | ", 42,0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %X%X | ", 42, 0);
// 	printf("Printed chars : %d\n", count);
// 	//
// 	// -------- test pointer --------
// 	printf("\n\n---- Test pointer ----\n");
// 	count = ft_printf("ft_printf >> %p | ", NULL);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %p | ", NULL);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %p | ", ptr);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %p | ", ptr);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %p%p | ", ptr, NULL);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %p%p | ", ptr, NULL);
// 	printf("Printed chars : %d\n", count);
// 	//
// 	// -------- test %u --------
// 	printf("\n\n---- Test %%u ----\n");
// 	count = ft_printf("ft_printf >> %u | ", 0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %u | ", 0);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %u | ", 42);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %u | ", 42);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %u | ", 12345);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %u | ", 12345);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %u | ", 4294967294);
// 	// ft_printf("Printed chars : %d\n", count);
// 	// count = printf("   printf >> %u | ", 4294967294);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %u | ", 4294967295);
// 	ft_printf("Printed chars : %d\n", count);
// 	// count = printf("   printf >> %u | ", 4294967295);
// 	// printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %u%u | ", 12345, 0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %u%u | ", 12345, 0);
// 	printf("Printed chars : %d\n", count);
// 	// -------- test identical --------
// 	printf("\n\n---- Test identical ----\n");
// 	count = ft_printf("ft_printf >> %c%c | ", 'A', 'B');
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %c%c | ", 'A', 'B');
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %s%s", "Hello ", "World ! | ");
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %s%s", "Hello ", "World ! | ");
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %d%d | ", -7000, 42);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %d%d | ", -7000, 42);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %x%x | ", 42,0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %x%x | ", 42, 0);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %X%X | ", 42,0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %X%X | ", 42, 0);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %p%p | ", ptr, NULL);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %p%p | ", ptr, NULL);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %u%u | ", 12345, 0);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %u%u | ", 12345, 0);
// 	printf("Printed chars : %d\n", count);
// 	// -------- test multiple --------
// 	printf("\n\n---- Test multiple ----\n");
// 	count = ft_printf("ft_printf >> %c %s %p | ", 'A', "Hi", ptr);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %c %s %p | ", 'A', "Hi", ptr);
// 	printf("Printed chars : %d\n", count);
// 	count = ft_printf("ft_printf >> %x %X %% %u | ", 42, 42, 12345);
// 	ft_printf("Printed chars : %d\n", count);
// 	count = printf("   printf >> %x %X %% %u | ", 42, 42, 12345);
// 	printf("Printed chars : %d\n", count);
// 	return (0);
// }