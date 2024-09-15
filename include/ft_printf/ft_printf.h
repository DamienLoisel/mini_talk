/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:44:24 by dloisel           #+#    #+#             */
/*   Updated: 2024/05/21 22:44:36 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base, int min_maj);
int	print_pointer(void *ptr);

#endif
