/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:32:04 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/08/16 19:32:15 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_to_str(char *num, unsigned long long addr, char *base)
{
	int	i;

	i = 0;
	if (addr == 0)
		num[i++] = '0';
	while (addr > 0)
	{
		num[i] = base[addr % 16];
		i++;
		addr /= 16;
	}
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addr;
	char				num[16];
	int					count;
	int					i;

	addr = (unsigned long long)ptr;
	if (addr == 0)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	i = ft_ptr_to_str(num, addr, "0123456789abcdef") - 1;
	while (i >= 0)
		count += ft_print_char(num[i--]);
	return (count);
}
