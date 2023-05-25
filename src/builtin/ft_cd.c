/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:59:53 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 14:07:24 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

void	check_old_path(void)
{
	char	**s;
	int		i;

	s = environ;
	i = 0;
	while (s[i])
	{
		if (findSubstring(s[i], "OLDPWD"))
			printf("%s\n [%d] \n", s[i], i);
		i++;
	}
}

char	*save_old_path(void)
{
	char	*s;

	s = ft_var_content("OLDPWD", head_ref);
	return (s);
}

int	cd(int argc, char **argv)
{
	char	*now;
	char	*curr;
	char	arg[1024];

	(void) argc;
	if (ft_strcmp(argv[1], "-"))
	{
		now = getcwd(arg, 1024);
		curr = save_old_path();
	}
	if (!ft_strcmp(argv[1], "~"))
	{
		ft_home_dir();
		return (0);
	}
	if (!ft_strcmp(argv[1], "-"))
	{
		ft_prev_dir(now);
		return (0);
	}
	else
	{
		chdir(argv[1]);
	}
	return (0);
}
