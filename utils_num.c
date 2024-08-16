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

static int	ft_handle_negative(long *nbr)
{
	if (*nbr < 0)
	{
		*nbr = -(*nbr);
		return (ft_print_char('-'));
	}
	return (0);
}

static int	ft_num_to_str(char *num, long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		num[i++] = '0';
	while (nbr > 0)
	{
		num[i] = (nbr % 10) + '0';
		i++;
		nbr /= 10;
	}
	return (i);
}

int	ft_print_num(int n)
{
	char	num[12];
	int		count;
	int		i;
	long	nbr;

	nbr = n;
	count = ft_handle_negative(&nbr);
	i = ft_num_to_str(num, nbr) - 1;
	while (i >= 0)
		count += ft_print_char(num[i--]);
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
