/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:53:54 by abasarud          #+#    #+#             */
/*   Updated: 2023/04/12 12:53:54 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	i = 0;
	nb_strs = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

// static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
// {
// 	unsigned int	i;

// 	*next_str += *next_str_len;
// 	*next_str_len = 0;
// 	i = 0;
// 	while (**next_str && (**next_str == c))
// 		(*next_str)++;
// 	while ((*next_str)[i])
// 	{
// 		if ((*next_str)[i] == c)
// 			return ;
// 		(*next_str_len)++;
// 		i++;
// 	}
// }

static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
{
	unsigned int	i;
    int	in_quotes;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	in_quotes = 0;
	while (**next_str && (**next_str == c || in_quotes))
	{
		if (**next_str == '"' && (*((*next_str) - 1) != '\\' || *((*next_str) - 2) == '\\'))
			in_quotes = !in_quotes;
		(*next_str)++;
	}
	while ((*next_str)[i] && (!in_quotes || (*next_str)[i] != '"'))
	{
		if ((*next_str)[i] == c && !in_quotes)
			return ;
		(*next_str_len)++;
		i++;
	}
}


char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	tab = malloc(sizeof(char *) * (nb_strs + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		tab[i] = malloc(sizeof(char) * (next_str_len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}