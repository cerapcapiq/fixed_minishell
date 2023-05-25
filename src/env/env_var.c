/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:55 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/25 15:06:09 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


struct s_node	*ft_var_main(char *argv, struct s_node *head_ref)
{
	struct s_node	*temp;

	temp = NULL;
	head_ref = create_list(&head_ref, argv);
	temp = head_ref;
	return (temp);
}

struct s_node	*ft_link_env(void)
{
	char	**s;

	s = environ;
	while (*s)
	{
		head_ref = ft_var_main(*s, head_ref);
		s++;
	}
	return (head_ref);
}

void	get_env(void)
{
	char	**s;
	int		i;

	s = environ;
	i = 0;
	while (s[i] != NULL)
	{
		i++;
	}
	return ;
}

// char	**ft_getenv()
// {
// 	char	**s;
// 	int		i;


// 	s = environ;
// 	i = 0;
// 	while (s[i] != NULL)
// 	{
// 		if (it_works(s[i]))
// 		{
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (s);
// }
