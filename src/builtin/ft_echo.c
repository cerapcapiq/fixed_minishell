/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:06 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/19 11:33:20 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../libft/libft.h"

void	print_echo_args(char **argv, int start)
{
	int	i;

	i = start;
	while (argv[i])
	{
		if (closed_quote(argv[i]) || closed_dub_quote(argv[i]))
			argv[i] = ft_delete_quote(argv[i]);
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
}

int	echo(int argc, char **argv, t_token curr)
{
	int	i;
	int	flag;
	int len = ft_strlen(*argv);

	if (argc < 2)
		return (1);
	i = 1;
	flag = 0;
	if (argv[i] && ft_strncmp(argv[i], "-n", 2) == 0)
	{
		flag = 1;
		i++;
	}
	if (curr.quote != 1 && ft_dollar(argv[i]))
	{
		argv[i] = ft_delete_quote(argv[i]);
		if (ft_dollar(argv[i]))
			argv[i] = strremove(argv[i], "$");
		// if (!get_the_new_var(argv[i], head))
		// {
		// 	// if (!show_var(argv[i], head_ref))
		// 		g_exit_num = 100;
		// }
	}
	else
		print_echo_args(argv, i);
	if (flag == 0)
		printf("\n");
	printf("how many %d", len);
	return (0);
}

/*int	echo(int argc, char **argv, t_token curr)
{
	int		flag;
	char	*arg;
	int		i;

	if (argc < 2)
		return (1);
	flag = 0;
	if (ft_strncmp(argv[1], "-n", 2) == 0)
	{
		flag = 1;
		argv++;
		argc--;
	}
	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		if (curr.quote == 2 && ft_dollar(arg))
		{
			show_var(ft_delete_quote(strremove(arg, "$")), head_ref);
			printf("in here\n");
		}
		else if (curr.quote == 0)
		{
			if (ft_dollar(arg))
				show_var(strremove(arg, "$"), head_ref);
			else
				printf("%s", arg);
			if (i < argc - 1)
				printf(" ");
		}
		else
			printf("%s", arg);
		i++;
	}
	if (flag == 0)
		printf("\n");
	return (0);
}*/
