/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:00:27 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/11 12:55:59 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	mini_exit(char **argv)
{
	agrv_free(argv);
	wait(NULL);
	printf("BYE\n");
	exit(0);
}

void	ft_error(int err_num)
{
	g_exit_num = err_num;
}

void	ft_error_exit(int g_exit_num)
{
	ft_error(g_exit_num);
}
