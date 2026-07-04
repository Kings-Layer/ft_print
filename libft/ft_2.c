/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:57:43 by vgurginy          #+#    #+#             */
/*   Updated: 2026/01/28 16:55:21 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char*s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

void	*ft_memset(void*s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*ptr;

	ch = c;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = ch;
		--n;
		++ptr;
	}
	return (s);
}

void	ft_bzero(void*s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			--n;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
