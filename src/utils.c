/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:01:22 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/07/24 16:33:32 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_write_str(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		count += ft_print_char(*str);
		str++;
	}
	return (count);
}

int	ft_print_num(int n)
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
		count = ft_print_str("(nil)");
	while (addr > 0)
	{
		num[i++] = base[addr % 16];
		addr /= 16;
	}
	while (i--)
		count += ft_print_char(num[i]);
	return (count);
}
