/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:14:36 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/18 16:56:16 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	token_free(t_token *tok)
{
	t_token	*temp;

	while (tok)
	{
		temp = tok;
		tok = tok->next;
		free(temp->str);
		free(temp);
		temp = tok;
	}
}

void	agrv_free(char **argv)
{
	int	i;

	if (argv == NULL)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i++]);
	}
	free(argv);
}
