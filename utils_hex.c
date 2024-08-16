/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:31:41 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/08/16 19:31:50 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	char	*base;
	char	num[8];
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
		return (ft_print_char('0'));
	while (n > 0)
	{
		num[i++] = base[n % 16];
		n /= 16;
	}
	while (i--)
		count += ft_print_char(num[i]);
	return (count);
}
