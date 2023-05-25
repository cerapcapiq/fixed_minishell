/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:15:51 by abasarud          #+#    #+#             */
/*   Updated: 2023/04/12 14:38:10 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#define _XOPEN_SOURCE 600

#define TMP_FILE	"temporary_file.txt"
#define IN	0
#define OUT	1

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

int	redirect_input(t_mini *ms, t_token *token)
{
	if (ms->input != -1)
		close(ms->input);
	ms->input = open(token->str, O_RDONLY, S_IRWXU);
	if (ms->input == -1)
	{
		printf("minishell: %s : No such file or directory\n", token->str);
		return (1);
	}
	dup2(ms->input, STDIN_FILENO);
	return (0);
}

int	redirect_output(t_mini *ms, t_token *token, int type)
{
	if (ms->output != -1)
		close(ms->output);
	if (type == TRUNC)
		ms->output = open(token->str, O_CREAT | O_WRONLY
				| O_TRUNC, S_IRWXU);
	else if (type == APPEND)
		ms->output = open(token->str, O_CREAT | O_WRONLY
				| O_APPEND, S_IRWXU);
	if (ms->output == -1)
	{
		printf("minishell: %s : No such file or directory\n", token->str);
		return (1);
	}
	dup2(ms->output, STDOUT_FILENO);
	return (0);
}
