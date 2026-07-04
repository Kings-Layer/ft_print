/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:06:51 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/03 17:07:31 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	*free_all(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
	free(res);
	return (NULL);
}

static char	*get_word(const char *s, int *i, char c)
{
	int		start;
	int		len;
	char	*word;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	len = 0;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			res[i] = get_word(s, &j, c);
			if (!res[i])
				return (free_all(res, i - 1));
			i++;
		}
		else
			j++;
	}
	res[i] = NULL;
	return (res);
}
