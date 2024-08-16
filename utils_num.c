/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:33:21 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/07/24 17:33:25 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int n)
{
	char	num[12];
	int		count;
	int		i;
	long	nbr;

	count = 0;
	i = 0;
	nbr = n;
	if (nbr == 0)
		return (ft_print_char('0'));
	if (nbr < 0)
	{
		count += ft_print_char('-');
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		num[i] = (nbr % 10) + '0';
		i++;
		nbr /= 10;
	}
	i--;
	while (i >= 0)
	{
		count += ft_print_char(num[i]);
		i--;
	}
	return (count);
}

int	ft_print_unum(unsigned int n)
{
	char	num[10];
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (n == 0)
		return (ft_print_char('0'));
	while (n > 0)
	{
		num[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		count += ft_print_char(num[i]);
	return (count);
}

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

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addr;
	char				*base;
	char				num[16];
	int					count;
	int					i;

	addr = (unsigned long long)ptr;
	base = "0123456789abcdef";
	count = 0;
	i = 0;
	if (addr == 0)
		return (ft_print_str("(nil)"));
	count += ft_print_str("0x");
	while (addr > 0)
	{
		num[i] = base[addr % 16];
		i++;
		addr /= 16;
	}
	i--;
	while (i >= 0)
	{
		count += ft_print_char(num[i]);
		i--;
	}
	return (count);
}
