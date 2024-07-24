/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:45:19 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/07/24 16:45:23 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		num_char;

	num_char = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			num_char += ft_define_type(args, *(++format));
		else
			num_char += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (num_char);
}

int	ft_define_type(va_list args, const char format)
{
	int	num_char;

	num_char = 0;
	if (format == 'c')
		num_char += ft_print_str(va_arg(args, char *));
	else if (format == 's')
		num_char += ft_print_str(va_arg(args, char *));
	return (num_char);
}
