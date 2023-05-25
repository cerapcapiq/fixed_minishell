/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_var_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:03:47 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 14:07:24 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

//struct s_linked *head = NULL;

int	show_var(char *lineptr, struct s_node *head)
{
	int				i;
	char			*contact;
	struct s_node	*temp;

	i = 1;
	get_name(lineptr);
	contact = lineptr;
	temp = head;
	if (temp == NULL)
		g_exit_num = 67;
	else
	{
		while (temp != NULL)
		{
			if (findSubstring(temp->data, contact))
			{
				printf("%s", get_arg_content(temp->data));
				return (0);
			}
			temp = temp->nxtpointer;
			i++;
		}
	}
	return (0);
}

char	*ft_var_content(char *lineptr, struct s_node *head)
{
	char			*contact;
	char			*new;
	int				i;
	struct s_node	*temp;

	if (*lineptr == '$')
		lineptr++;
	contact = lineptr;
	new = NULL;
	i = 1;
	temp = head;
	while (temp != NULL)
	{
		if (!ft_strcmp(get_name(temp->data), contact))
		{
			new = get_arg_content(temp->data);
		}
		temp = temp->nxtpointer;
		i++;
	}
	return (new);
}

char	*get_arg_to_del(char *lineptr)
{
	int		i;
	char	*interesting_stuff;

	i = 0;
	while (i < ft_strlen(lineptr))
	{
		if (lineptr[i] == ' ')
		{
			interesting_stuff = lineptr + i + 1;
		}
		i++;
	}
	return (interesting_stuff);
}

char	*ft_remove_value(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '=');
	if (ptr != NULL)
		*ptr = '\0';
	return (ptr);
}
