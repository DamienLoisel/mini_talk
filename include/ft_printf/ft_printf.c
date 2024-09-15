/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:09:07 by dloisel           #+#    #+#             */
/*   Updated: 2024/05/29 12:13:32 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	specifier_verif(char format)
{
	char	*specifier;

	specifier = "cspdiuxX%";
	while (*specifier != '\0')
	{
		if (*specifier == format)
			return (0);
		specifier++;
	}
	return (1);
}

int	print_format(char specifier, va_list *ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(*ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(*ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(*ap, int), 10, 1);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(*ap, unsigned int), 16, 1);
	else if (specifier == 'X')
			count += print_digit((long)va_arg(*ap, unsigned int), 16, 2);
	else if (specifier == 'p')
		count += print_pointer(va_arg(*ap, void *));
	else if (specifier == 'u')
		count += print_digit((long)va_arg(*ap, unsigned int), 10, 1);
	else if (specifier == '%')
			count += write(1, "%", 1);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%' && !specifier_verif(*(format + 1)))
			count += print_format(*++format, &ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/*int	main(void)
{
	int	count;
	int	num;
	int	*ptr;

	num = 42;
	ptr = &num;
	printf("%x %x", 10, -10);
	fflush(stdout);
	count = ft_printf("%x %x", 10, -10);
	return (0);
}*/
