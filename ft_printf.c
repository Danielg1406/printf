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

int	ft_define_type(va_list args, const char format)
{
	int	num_char;

	num_char = 0;
	if (format == 'c')
		num_char += ft_print_char(va_arg(args, int));
	else if (format == 's')
		num_char += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		num_char += ft_print_num(va_arg(args, int));
	else if (format == 'u')
		num_char += ft_print_unum(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		num_char += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		num_char += ft_print_ptr(va_arg(args, void *));
	else if (format == '%')
		num_char += ft_print_char('%');
	return (num_char);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		num_char;

	num_char = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
			num_char += ft_define_type(args, format[++i]);
		else
			num_char += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (num_char);
}
