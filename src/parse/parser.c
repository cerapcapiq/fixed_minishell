/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:15:41 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/25 16:44:25 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"
#include <histedit.h>
#include <string.h>

static void	ft_strcpy(char *dst, char *begin, char *end)
{
	while (begin < end)
		*(dst++) = *(begin++);
	*dst = 0;
}

static int	handle_quotes_tw(char **s)
{
	char	quote;
	char	cancel;

	quote = **s;
	cancel = *(*s + 1);
	if (quote && quote == '\\' && (cancel == '\"' || cancel == '\''))
	{
		(*s) += 2;
		return (0);
	}
	if (!(quote == '\"' || quote == '\''))
		return (0);
	(*s)++;
	while (**s && **s != quote)
		(*s)++;
	if (**s == quote)
		(*s)++;
	return (1);
}

static int	get_tw(char *s, char c)
{
	int		res;

	res = 0;
	while (*s)
	{
		if (!(*s == c))
		{
			res++;
			if (handle_quotes_tw(&s))
				continue ;
			while (*s && !(*s == c))
				s++;
		}
		else
			s++;
	}
	return (res);
}

static int	handle_quotes(char **res, char *start, int *i, char **s)
{
	char	quote;
	char	cancel;

	quote = **s;
	cancel = *(*s + 1);
	if (quote && quote == '\\' && (cancel == '\"' || cancel == '\''))
	{
		(*s) += 2;
		return (0);
	}
	if (!(quote == '\"' || quote == '\''))
		return (0);
	(*s)++;
	while (**s && **s != quote)
	{
		if (**s == '\\')
			(*s)++;
		(*s)++;
	}
	if (**s == quote)
		(*s)++;
	res[*i] = (char *)malloc((char *)*s - start + 1);
	ft_strcpy(res[(*i)++], start, (char *)*s);
	return (1);
}

char	**ft_new_split(char *s, char c)
{
	char	*start;
	char	**res;
	int		i;

	if (!s)
		return (0);
	res = (char **)malloc((sizeof(char *) * (get_tw((char *)s, c) + 1)));
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			if (handle_quotes(res, start, &i, &s))
				continue ;
			while (*s && *s != c)
				s++;
			res[i] = (char *)malloc((char *)s - start + 1);
			ft_strcpy(res[i++], start, (char *)s);
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_whitespace(char *buff)
{
	while (*buff == '\t' || *buff == ' ' )
		buff++;
	if (*buff == '\0')
		exit(0);
}
char* add_spaces_around_pipe(const char* s)
{
    size_t len = ft_strlen(s);
    char* result = malloc(sizeof(char) * (len * 2 + 1));
    if (!result) {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (s[i] == '|' && ((i > 0 || s[i-1] != ' ') || (i < len - 1 || s[i+1] != ' '))) {
            result[j++] = ' ';
            result[j++] = '|';
            result[j++] = ' ';
        } else {
            result[j++] = s[i];
        }
    }
    result[j] = '\0';

    return result;
}

void exit_status()
{
char decimal_exit_status[20];

    snprintf(decimal_exit_status, sizeof(decimal_exit_status), "%d", g_exit_num);
    char command[256];
    snprintf(command, sizeof(command), "expr %s", decimal_exit_status);
}

void	parse(t_mini *mini, char *buff, Node* envListHead, MyNode *varListHead)
{
	char	**split;
	int		i;
	t_token	*first = NULL;
	char	*cpy = NULL;

	split = NULL;
	if (buff == NULL)
		exit(0);
    //buff = add_spaces_around_pipe(buff);
	cpy = ft_strdup(buff);
	split = ft_new_split(cpy, ' ');
	first = new_token(mini, *split);
	mini->tokens = first;
	i = 0;
	while (split[++i])
		token_addend(split[i], mini);
	execute(mini, envListHead, varListHead);
	mini->cmd = 1;
	token_free(mini->tokens);
	agrv_free(split);
}
