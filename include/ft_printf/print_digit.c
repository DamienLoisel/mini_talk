/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:24:28 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/14 22:15:12 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	print_digit(long n, int base, int min_maj)
{
	int		count;
	char	*symboles_min;
	char	*symboles_maj;

	symboles_min = "0123456789abcdef";
	symboles_maj = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return ((print_digit(-n, base, min_maj)) + 1);
	}
	else if (n < base)
	{
		if (min_maj == 1)
			return (print_char(symboles_min[n]));
		else
			return (print_char(symboles_maj[n]));
	}
	else
	{
		count = print_digit(n / base, base, min_maj);
		return (count + print_digit(n % base, base, min_maj));
	}
}
