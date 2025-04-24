/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doberes <doberes@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:18:21 by doberes           #+#    #+#             */
/*   Updated: 2025/02/22 17:24:36 by doberes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =========================================================================
// ------------------------------ Compilation ------------------------------
// =========================================================================

/*
	cc -Wall -Wextra -Werror -o test main.c -L. -lft
	-o test -> names the output executable 'test'
	-L. -> specifies that the library (libft.a) is in the current directory
	-lft -> links the program with libft
	
	The lib prefix is implicit in -lft, so -lft automatically reserches for
	'libft.a'.
	With the -l<name> option with gcc looks for a library named lib<name>.a.
	Static library naming convention : a static library must follow the naming
	format lib<name>.a. Since 'libft.a' followss this convention, so gcc can
	find it without explicitily specifying 'libft.a'.
*/

// =========================================================================
// -------------------------- Included libraries ---------------------------
// =========================================================================

#include "include/libft.h"

// =========================================================================
// --------------------------------- main ----------------------------------
// =========================================================================

int	main(void)
{
	ft_printf("Hello, world!\n");
	return (0);
}
