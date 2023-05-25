/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:12 by abasarud          #+#    #+#             */
/*   Updated: 2023/04/12 13:00:13 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	pwd(void)
{
	char	*path;

	path = getcwd(NULL, 1024);
	if (!path)
	{
		free(path);
		return (1);
	}
	printf("%s\n", path);
	free(path);
	return (0);
}
