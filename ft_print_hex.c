/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:51:40 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/04 22:13:38 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse_str(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		++i;
		--j;
	}
}

void	to_hex(unsigned long long num, int *count)
{
	int		i;
	char	str[(sizeof(unsigned long long) * 2) + 3];

	str[0] = '0';
	str[1] = 'x';
	i = 2;
	while (num != 0)
	{
		if ((num % 16) <= 9)
			str[i] = '0' + (num % 16);
		else
			str[i] = 'a' + ((num % 16) - 10);
		++i;
		num /= 16;
	}
	str[i] = '\0';
	reverse_str(str + 2);
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void	print_hex_lowercase(va_list *args, int *count)
{
	unsigned int	num;
	int				i;
	char			str[(sizeof(unsigned long long) * 2) + 1];

	num = va_arg(*args, unsigned int);
	if (num == 0)
	{
		write (1, "0", 1);
		(*count)++;
	}
	i = 0;
	while (num != 0)
	{
		if ((num % 16) <= 9)
			str[i] = '0' + (num % 16);
		else
			str[i] = 'a' + ((num % 16) - 10);
		++i;
		num /= 16;
	}
	str[i] = '\0';
	reverse_str(str);
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void	print_hex_uppercase(va_list *args, int *count)
{
	unsigned int	num;
	int				i;
	char			str[(sizeof(unsigned long long) * 2) + 1];

	num = va_arg(*args, unsigned int);
	if (num == 0)
	{
		write (1, "0", 1);
		(*count)++;
	}
	i = 0;
	while (num != 0)
	{
		if ((num % 16) <= 9)
			str[i] = '0' + (num % 16);
		else
			str[i] = 'A' + ((num % 16) - 10);
		++i;
		num /= 16;
	}
	str[i] = '\0';
	reverse_str(str);
	*count += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void	print_pointer(va_list *args, int *count)
{
	void				*pt;
	unsigned long long	ptr;

	pt = va_arg(*args, void *);
	if (!pt)
	{
		write (1, "(nil)", 5);
		*count += 5;
		return ;
	}
	ptr = (unsigned long long)pt;
	to_hex(ptr, count);
}
