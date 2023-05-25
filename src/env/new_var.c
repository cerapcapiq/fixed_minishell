/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:01:01 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 16:59:23 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_the_new_var(char *lineptr, t_env *l_env)
{
	int					i;
	char				*search;
	char				*new;
	t_env *temp;
	temp = l_env;

	i = 1;
	lineptr = ft_delete_quote(lineptr);
	if (*lineptr == '$')
		lineptr++;
	search = lineptr;
	while (temp != NULL)
	{
		if (findSubstring(temp->str, search))
		{
			new = get_arg_content(temp->str);
			printf("%s", new);
			return (temp->str);
		}
		temp = temp->next;
		i++;
	}
	return (NULL);
}


