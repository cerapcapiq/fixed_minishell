/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:59 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 15:30:52 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"
#define J 100000000

//struct s_linked *head = NULL;

struct s_node	*del_path(char *now)
{
	char	**s;
	int		i;
	size_t	len;

	i = 0;
	s = &now;
	while (s[i])
	{
		if (findSubstring(s[i], "PATH"))
		{
			len = ft_strlen(s[i]);
			ft_memcpy(s[i], now, len);
			printf("%s\n [%d] \n", s[i], i);
		}
		i++;
	}
	return (head_ref);
}

struct s_node*	ft_add_back(struct s_node* head_ref, char *cpy)
{
	struct s_node	*fs_node;
	struct s_node	*tmp;

	printf("add abck %s", cpy);
	fs_node = (struct s_node *)malloc(sizeof(struct s_node));
	if (fs_node == NULL)
	{
		printf(" Memory can not be allocated.");
		return head_ref;
	}
	else
	{
		printf("dobe\n");
		fs_node->data = cpy;
		fs_node->nxtpointer = NULL;

		if (head_ref == NULL) // List is empty
		{
			head_ref = fs_node; // Assign the new node as the head
		}
		else
		{
			tmp = head_ref;
			while (tmp->nxtpointer != NULL)
				tmp = tmp->nxtpointer;
			tmp->nxtpointer = fs_node; // Append the new node to the end of the list
		}
	}
	return (head_ref);
}

// struct s_linked	*ft_linked_list(char *cpy)
// {
// 	if (ft_strchr(cpy, '=') && !ft_detect_quote(cpy)
// 		&& !findSubstring(cpy, "export") && !findSubstring(cpy, "unset "))
// 	{
// 		head = *add_to_var(cpy, head);
// 		display_linked_s_node(head);
// 	}
// // 	// else if (findSubstring(cpy, "export "))
// 	//ft_export(cpy);
// // 	ft_unset(cpy);
// return (&head);
// }
