/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:15:48 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/09 14:49:08 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

int	ft_detect_quote(char *data)
{
	char	*arg_letters;
	int		i;
	int		j;
	int		k;

	arg_letters = data;
	i = 0;
	j = ft_strlen(arg_letters);
	while (i < j)
	{
		k = i + 1;
		while (k < j)
		{
			if (arg_letters[i] == arg_letters[k])
			{
				if (arg_letters[i] == '\'' || arg_letters[i] == '\"')
					return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int	ft_double_detect_quote(char *data)
{
	char	*arg_letters;
	int		i;
	int		j;
	int		k;

	arg_letters = data;
	i = 0;
	j = ft_strlen(arg_letters);
	while (i < j)
	{
		k = i + 1;
		while (k < j)
		{
			if (arg_letters[i] == arg_letters[k])
			{
				if (arg_letters[i] == '\"')
					return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}

int	closed_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			while (line[i] != '\0')
			{
				if (line[i] == '\'')
				{
					return (1);
					break ;
				}
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	closed_dub_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
		{
			while (line[i] != '\0')
			{
				if (line[i] == '\"')
				{
					return (1);
					break ;
				}
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	detect_q(char *data)
{
	char	*arg_letters;
	int		i;
	int		k;
	int		j;

	arg_letters = data;
	i = 0;
	j = ft_strlen(arg_letters);
	while (i < j)
	{
		k = i + 1;
		while (k < j)
		{
			if (arg_letters[i] == arg_letters[k])
			{
				if (arg_letters[i] == '\'')
					return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}
