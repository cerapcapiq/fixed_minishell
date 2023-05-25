/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:05:30 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 17:11:26 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void display_linked_s_node(t_env *l_env)
{
	t_env	*temp;

	temp = l_env;
	while (temp != NULL)
	{
		if (temp->next == NULL)
		{
			printf(" %s->NULL\n", temp->str);
		}
		else
		{
			printf("\n%s->", temp->str);
		}
		temp = temp->next;
	}
}

char	*ft_add_var_content(char *lineptr, struct s_linked *head)
{
	char				*contact;
	char				*new;
	int					i;
	struct s_linked		*temp;

	temp = head;
	if (*lineptr == '$')
		lineptr++;
	contact = lineptr;
	new = NULL;
	i = 1;
	while (temp != NULL)
	{
		if (findSubstring(temp->data, contact))
		{
			new = temp->data;
		}
		temp = temp->next;
		i++;
	}
	return (new);
}

// struct s_linked	*ft_create_list(struct s_linked **head, char *str)
// {
// 	char				*s_nodedata;
// 	struct s_linked		*new;
// 	struct s_linked		*last;

// 	new = malloc(sizeof(struct s_linked));
// 	s_nodedata = str;
// 	new->data = s_nodedata;
// 	new->next = NULL;
// 	if (*head == NULL)
// 		*head = new;
// 	else
// 	{
// 		last = *head;
// 		while (last->next != NULL)
// 		{
// 			last = last->next;
// 		}
// 		last->next = new;
// 	}
// 	return (*head);
// }

struct s_linked *ft_create_list(struct s_linked **head, char *str)
{
	struct s_linked *new = malloc(sizeof(struct s_linked));
	if (new == NULL) {
		// Memory allocation failed
		return NULL;
	}

	// Allocate memory for data and copy the string
	new->data = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (new->data == NULL) {
		// Memory allocation failed
		free(new); // Clean up the previously allocated node
		return NULL;
	}

	ft_strlcpy(new->data, str, ft_strlen(str));
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		struct s_linked *last = *head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
	//display_linked_s_node(l_env);

	return *head;
}


t_env *ft_list_added(t_env *l_env, char *input)
{
	t_env *new;
 	new = malloc(sizeof(t_env));
	if (new == NULL) {
		// Memory allocation failed
		return NULL;
	}

	// Allocate memory for data and copy the string
	new->str = malloc((ft_strlen(input) + 1) * sizeof(char));
	if (new->str == NULL) {
		// Memory allocation failed
		free(new); // Clean up the previously allocated node
		return NULL;
	}

	ft_strlcpy(new->str, input, ft_strlen(input));
	new->next = NULL;

	if (l_env == NULL)
		l_env= new;
	else
	{
		t_env *last = l_env;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
	display_linked_s_node(l_env);

	return l_env;
}