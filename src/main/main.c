/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:14:55 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/25 17:03:48 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	//ft_check_error(E_MALLOC, (ssize_t)ptr);
	return (ptr);
}

// static void	set_env_list(t_env *env_head, char **envp)
// {
// 	int	i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		env_add(env_head, envp[i]);
// 		++i;
// 	}
// }

// t_env	*set_shell()
// {
// 	t_env	*env_head;

// 	env_head = (t_env*)malloc(sizeof(t_env));
// 	env_head->str = NULL;
// 	env_head->key = NULL;
// 	env_head->value = NULL;
// 	env_head->next = NULL;
// 	return (env_head);
// }


t_mini	*init_mini(void)
{
	t_mini	*mini;

	mini = (t_mini *)malloc(sizeof(t_mini));
	mini->tokens = 0;
	mini->cmd = 1;
	mini->pipe_read = -1;
	mini->pipe_write = -1;
	mini->input = -1;
	mini->output = -1;
	mini->stdin = dup(STDIN_FILENO);
	mini->stdout = dup(STDOUT_FILENO);
	mini->execute_code = 0;
	mini->env = NULL;
	mini->envListHead = NULL;
	mini->varListHead = NULL;
	return (mini);
}

void	init_main(int argc, char **argv)
{
	if (argc > 1 || argv[1])
	{
		printf("one argc ./minishell ");
		exit(1);
	}
}

char	*display_readline(char *input)
{
	input = readline("@minishell> ");
	return (input);
}

static void	read_input(t_mini *mini, char *input, Node* envListHead, MyNode *varListHead)
{

	input = display_readline(input);
	ft_whitespace(input);
	parse(mini, input, envListHead, varListHead);
	add_history(input);
	dup2(mini->stdin, STDIN_FILENO);
	dup2(mini->stdout, STDOUT_FILENO);
	free(input);
}

int	main(int argc, char *argv[], char* env[] )
{
	t_mini	*mini;
	char	*buff;
	Node* envListHead;
	MyNode* varListHead = NULL;



	define_signal();
	init_main(argc, argv);
	mini = init_mini();
	g_exit_num = 0;
	//varListHead = initializeMyNode(varListHead);
	envListHead = getTerminalEnvList(env);
	
	while (1)
	{
		buff = NULL;
		read_input(mini, buff, envListHead, varListHead);
	}
	freeList(envListHead);
	var_freeList(varListHead);
	return (mini->execute_code);
}
