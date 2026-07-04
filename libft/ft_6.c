/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:06:31 by vgurginy          #+#    #+#             */
/*   Updated: 2026/01/30 20:51:42 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	size = ft_strlen(s1);
	while (i < size)
	{
		str[i] = s1[i];
		++i;
	}
	size += ft_strlen(s2);
	j = 0;
	while (i < size)
	{
		str[i] = s2[j++];
		++i;
	}
	str[i] = '\0';
	return (str);
}

static int	is_in_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (i < j && is_in_set(s1[i], set))
		i++;
	while (j > i && is_in_set(s1[j - 1], set))
		j--;
	size = j - i;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + i, size);
	str[size] = '\0';
	return (str);
}
