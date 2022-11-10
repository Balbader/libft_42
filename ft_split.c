/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:09:28 by baalbade          #+#    #+#             */
/*   Updated: 2022/08/25 08:54:04 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static void	ft_free_strs(char *strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
	{
		free(strings);
		i++;
	}
	free(strings);
}

static char	*ft_strdup_spe(char const *s, char c)
{
	size_t	i;
	char	*dst;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words_nb;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	words_nb = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words_nb + 1));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (j < words_nb)
	{
		while (s[i] && s[i] == c)
			i++;
		tab[j++] = ft_strdup_spe(s + i, c);
		if (!tab[j])
			ft_free_strs(tab[j]);
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = 0;
	return (tab);
}
