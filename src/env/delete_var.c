/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:04:16 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/19 11:56:41 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"
#define J 100000000

char	*prepare_input(char *lineptr)
{
	char	*p;

	lineptr = strremove(lineptr, "unset ");
	if (closed_dub_quote(lineptr))
	{
		p = ft_delete_quote(lineptr);
		printf("deleted quote %s", p);
	}
	else
		p = lineptr;
	if (*p == '$')
		p++;
	return (p);
}

struct s_node	*delete_head_var(struct s_node *head)
{
	struct s_node	*temp;

	temp = head->nxtpointer;
	head->nxtpointer = NULL;
	free(head);
	return (temp);
}

struct s_node	*delete_next_var(struct s_node *head, char *str)
{
	struct s_node	*tmp;
	struct s_node	*current;

	current = head;
	while (current->nxtpointer != NULL)
	{
		if (!ft_strcmp(get_name(current->nxtpointer->data), str))
		{
			tmp = current->nxtpointer;
			current->nxtpointer = current->nxtpointer->nxtpointer;
			printf("\nElement deleted is : %s\n", tmp->data);
			free (tmp);
			break ;
		}
		else
			current = current->nxtpointer;
	}
	return (head);
}

struct s_node	*delete_var(char *lineptr, struct s_node *head_ref)
{
	struct s_node	*temp;
	char			*p;
	char			*str;

	temp = head_ref;
	p = prepare_input(lineptr);
	str = get_name(p);
	if (!ft_strcmp(get_name(head_ref->data), str))
		head_ref = delete_head_var(head_ref);
	else
		head_ref = delete_next_var(head_ref, str);
	return (head_ref);
}
