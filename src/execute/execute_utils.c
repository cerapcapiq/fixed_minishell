/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:06:32 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 14:08:33 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

#include <string.h>

char	*strremove(char *str, const char *sub)
{
	char	*p;
	char	*q;
	char	*r;
	size_t	len;

	if (*sub)
	{
		q = strstr(str, sub);
		r = q;
		if (q != NULL)
		{
			len = ft_strlen(sub);
			while (r != NULL)
			{
				p = r + len;
				r = strstr(p, sub);
				while (p < r)
					*q++ = *p++;
			}
			while (*q != '\0')
				*q++ = *p++;
		}
	}
	return (str);
}

int	count_argc(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		++i;
	return (i);
}

void	call_pipe_redirect(t_mini *mini, t_token *command, t_token *tok)
{
	if (!command)
		return ;
	if (tok && tok->type == PIPE)
	{
		create_pipe(mini);
		tok = tok->next;
	}
	else if (tok && (tok->type == TRUNC || tok ->type == APPEND))
	{
		tok = tok->next;
		tok->type = ARG;
		redirect_output(mini, tok, tok->prev->type);
	}
	else if (tok && (tok->type == INPUT))
	{
		tok = tok->next;
		tok->type = ARG;
		redirect_input(mini, tok);
	}
	else if (tok && tok->type == HEREDOC)
	{	
		tok = tok->next;
		tok->type = ARG;
		here_doc_input(tok, 0);
	}
}

//converts arguments into an array of strings
char	**convert_argv(t_token	*tokens)
{
	int		i;
	t_token	*tok;
	char	**res;

	i = 0;
	tok = tokens;
	while (tok && (tok->type == ARG || tok->type == BUILTIN
			|| tok->type == CMD || tok->type == 9))
	{
		i++;
		tok = tok->next;
	}
	if (!i)
		return (0);
	res = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	tok = tokens;
	while (tok && (tok->type == ARG || tok->type == BUILTIN
			|| tok->type == CMD || tok->type == 9))
	{
		res[i++] = ft_strdup(tok->str);
		tok = tok->next;
	}
	res[i] = 0;
	return (res);
}
