/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:59:45 by abasarud          #+#    #+#             */
/*   Updated: 2023/04/12 12:59:46 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

void	ft_change_path(char *path)
{
	chdir(path);
	printf(" change to %s\n", path);
}

void	ft_home_dir(void)
{
	char	*path;

	path = ft_strdup(getenv("HOME"));
	ft_change_path(path);
}

void	ft_prev_dir(char *path)
{
	ft_change_path(path);
}
