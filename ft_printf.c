/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:14:17 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/07 18:26:03 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_due_to_percent(const char *format, int *count)
{
	int	i;

	if (!format)
		return (NULL);
	i = 0;
	while (format[i] != '%' && format[i] != '\0')
	{
		ft_putchar_fd(format[i], 1);
		i++;
		(*count)++;
	}
	if (format[i] == '%')
		return ((char *)(format + i + 1));
	return (NULL);
}

void	print_single_char(va_list *args, int *count)
{
	char	c;

	c = va_arg(*args, int);
	ft_putchar_fd(c, 1);
	++(*count);
}

void	print_string(va_list *args, int *count)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
	{
		write (1, "(null)", 6);
		*count += 6;
		return ;
	}
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void	handle_conversion(char c, va_list *args, int *count)
{
	if (c == 'c')
		print_single_char(args, count);
	else if (c == 's')
		print_string(args, count);
	else if (c == 'p')
		print_pointer(args, count);
	else if (c == 'd' || c == 'i')
		print_dec_int(args, count);
	else if (c == 'u')
		print_unsigned_int(args, count);
	else if (c == 'x')
		print_hex_lowercase(args, count);
	else if (c == 'X')
		print_hex_uppercase(args, count);
	else if (c == '%')
		print_percent(count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*fmt;
	int		count;

	if (!format)
		return (0);
	count = 0;
	va_start(args, format);
	fmt = print_due_to_percent(format, &count);
	while (fmt)
	{
		handle_conversion(*fmt, &args, &count);
		++fmt;
		fmt = print_due_to_percent(fmt, &count);
	}
	return (count);
}
