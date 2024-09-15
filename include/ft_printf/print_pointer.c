/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:57:22 by dloisel           #+#    #+#             */
/*   Updated: 2024/05/22 14:24:34 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_pointer(void *ptr)
{
	unsigned long	address;
	char			buffer[20];
	int				index;
	int				digit;

	index = 20;
	address = (unsigned long)ptr;
	buffer[index--] = '\0';
	if (address == 0)
		return (write(1, "(nil)", 5));
	while (address > 0 && index >= 0)
	{
		digit = address % 16;
		if (digit < 10)
			buffer[index--] = '0' + digit;
		else
			buffer[index--] = 'a' + (digit - 10);
		address /= 16;
	}
	buffer[index--] = 'x';
	buffer[index] = '0';
	write(1, &buffer[index], 20 - index);
	return (20 - index);
}
