/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:47:05 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/04 23:06:43 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr(unsigned int n, int *count)
{
	char	c;

	if (n > 9)
	{
		putnbr(n / 10, count);
	}
	c = '0' + (n % 10);
	write (1, &c, 1);
	(*count)++;
}

void	print_num(int num, int *count)
{
	char	c;

	if (num == 0)
		return ;
	if (num < 0)
		num *= -1;
	if (num > 9)
		print_num(num / 10, count);
	c = '0' + (num % 10);
	write (1, &c, 1);
	(*count)++;
}

void	print_dec_int(va_list *args, int *count)
{
	int			num;
	int			n;
	char		c;

	num = va_arg(*args, int);
	if (num < 0)
	{
		(*count)++;
		write (1, "-", 1);
	}
	n = num % 10;
	num /= 10;
	print_num(num, count);
	if (n < 0)
		n *= -1;
	c = '0' + n;
	write (1, &c, 1);
	(*count)++;
}

void	print_unsigned_int(va_list *args, int *count)
{
	unsigned int	num;

	num = va_arg(*args, unsigned int);
	putnbr(num, count);
}

void	print_percent(int *count)
{
	ft_putchar_fd('%', 1);
	++(*count);
}
