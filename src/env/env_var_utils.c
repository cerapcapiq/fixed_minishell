/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:01:05 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 14:09:11 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

struct s_node	*display_s_node(struct s_node *head_ref)
{
	struct s_node	*temp;

	temp = head_ref;
	while (temp != NULL)
	{
		if (temp->nxtpointer == NULL)
		{
			printf("%s\nNULL", temp->data);
		}
		else
		{
			printf("%s\n", temp->data);
		}
		temp = temp->nxtpointer;
	}
	return (head_ref);
}

char	*get_name(char *linestr)
{
	char	*str;
	char	*cpy;
	int		i;

	str = linestr;
	i = 0;
	while (str[i] != '=')
		i++;
	cpy = ft_substr(str, 0, i);
	return (cpy);
}

#include <string.h>
void	get_arg(char *lineptr)
{
	char	*str;
	char	*arg;
	char	*after;
	size_t	j;
	size_t	len;

	after = NULL;
	j = 0;
	str = lineptr;
	arg = str;
	if (arg == ft_strchr(str, '='))
	{
		len = ft_strlen (++arg);
		if (len > j - 1)
		{
			printf("error");
		}
		ft_memcpy (after, arg, len + 1);
		printf ("the arg(value) is %s\n", arg);
	}
}

char	*get_arg_content(char *lineptr)
{
	int		i;
	char	*value;
	char	*new;

	i = 0;
	new = NULL;
	value = strstr(lineptr, "=");
	if (value != NULL)
	{
		new = value + 1;
	}
	return (new);
}

// struct s_node	*create_list(struct s_node **head_ref, char *lineptr)
// {
// if (head_ref == NULL || lineptr == NULL) {
// 		// Invalid input parameters
// 		return NULL;
// 	}
// 	char			*s_nodedata;
// 	struct s_node	*new;
// 	struct s_node	*last;

// 	new = malloc(sizeof(struct s_node));
// 	s_nodedata = lineptr;
// 	new->data = s_nodedata;
// 	new->nxtpointer = NULL;
// 	if (*head_ref == NULL)
// 		*head_ref = new;
// 	else
// 	{
// 		last = *head_ref;
// 		while (last->nxtpointer != NULL)
// 		{
// 			last = last->nxtpointer;
// 		}
// 		last->nxtpointer = new;
// 	}
// 	return (*head_ref);
// }

#include <stdlib.h>
#include <string.h>

struct s_node *create_list(struct s_node **head_ref,  char *lineptr) {
	if (lineptr == NULL) {
		// Invalid input parameters
		return NULL;
	}

	struct s_node *new_node = malloc(sizeof(struct s_node));
	if (new_node == NULL) {
		// Memory allocation failed
		return NULL;
	}

	// Allocate memory for data and copy the string
	new_node->data = malloc((strlen(lineptr) + 1) * sizeof(char));
	if (new_node->data == NULL) {
		// Memory allocation failed
		free(new_node); // Clean up the previously allocated node
		return NULL;
	}

	strcpy(new_node->data, lineptr);
	new_node->nxtpointer = NULL;

	if (*head_ref == NULL) {
		*head_ref = new_node;
	} else {
		struct s_node *last = *head_ref;
		while (last->nxtpointer != NULL) {
			last = last->nxtpointer;
		}
		last->nxtpointer = new_node;
	}

	return *head_ref;
}
