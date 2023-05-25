/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:42:25 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 14:07:24 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

int	for_env(char *token)
{
	if (findSubstring(token, "="))
	{
		return (ENV);
		printf("in able env\n");
	}
	return (0);
}

int	ft_detect_dollar(char	*s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	ft_dollar(char *new)
{
	while (*new != '\0')
	{
		if (*new == '$')
			return (1);
		new++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*char	*ft_delete_quote(char *data)
{
	char	*new = data;
	//int		i;
	//int		len;
	//char	*curr;

	// i = 0;
	// new = ft_strdup(data);
	// len = ft_strlen(new);
	// ft_memmove(new, new+1, len - 2);
	// new[len - 2] = '\0';
	new = strremove(new, "\"");
	return (new);
}*/

#include <string.h>

char *ft_delete_quote(char* data) {
    int len = ft_strlen(data);
	char *new = NULL;
    if (len >= 2 && data[0] == '"' && data[len - 1] == '"') {
        ft_memmove(data, data + 1, len - 2);
        data[len - 2] = '\0';
    }
	new = data;
	return new;
}