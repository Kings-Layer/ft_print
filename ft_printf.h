/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:39:03 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/04 23:07:12 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

char	*print_due_to_percent(const char *format, int *count);
void	print_single_char(va_list *args, int *count);
void	print_string(va_list *args, int *count);
void	print_pointer(va_list *args, int *count);
void	print_dec_int(va_list *args, int *count);
void	print_unsigned_int(va_list *args, int *count);
void	print_hex_lowercase(va_list *args, int *count);
void	print_hex_uppercase(va_list *args, int *count);
void	to_hex(unsigned long long num, int *count);
void	reverse_str(char *str);
void	print_percent(int *count);
void	handle_conversions(char c, va_list *args, int *count);
int		ft_printf(const char *format, ...);

#endif
