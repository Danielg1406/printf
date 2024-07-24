/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:29:22 by dgomez-a          #+#    #+#             */
/*   Updated: 2024/07/24 17:30:55 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_num(int n);
int	ft_print_unum(unsigned int n);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_ptr(void *ptr);

#endif
