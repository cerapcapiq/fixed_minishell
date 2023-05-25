/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:06:35 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/25 16:47:27 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
struct s_node *head_ref = NULL;

//calls the builtin function for execution

int	call_builtin(char **argv, char *command, t_token token, Node* envListHead, MyNode* varListHead)
{
	int	argc;
	int	builtin_cmd;

	argc = count_argc(argv);
	builtin_cmd = 0;
	if (ft_strchr(command, '='))
	{

		printf("yes we are\n");
		 var_insertNode(&varListHead, command, *argv);
		printf("insoide add = %s", *argv);
		//display_linked_s_node(*head);
	}
	if (!ft_strcmp(command, "echo"))
		builtin_cmd = echo(argc, argv, *token.next);
	else if (!ft_strcmp(command, "pwd"))
		builtin_cmd = pwd();
	else if (!ft_strcmp(command, "export"))
	 	 insertNode(&envListHead, command, *argv);
	else if (!ft_strcmp(command, "env"))
		printList(envListHead);
	else if (!ft_strcmp(command, "unset"))
		 deleteNode(&envListHead, argv);

	g_exit_num = builtin_cmd;
	return (builtin_cmd);
}

static	void	post_call(char **argv, char *command, t_mini *ms, int exit_code, Node *envListHead,MyNode* varListHead)
{
	int	argc;

	argc = count_argc(argv);
	if (!ft_strcmp(command, "cd"))
		cd(argc, argv);
else if (ft_strchr(command, '='))
	{

		printf("yes we are\n");
		 var_insertNode(&varListHead, command, *argv);
		printf("insoide add = %s", *argv);
		//display_linked_s_node(*head);
	}
	else if (!ft_strcmp(command, "exit"))
		mini_exit(argv);
		else if (!ft_strcmp(command, "export"))
	 	insertNode(&envListHead, command, *argv);
else if (!ft_strcmp(command, "unset"))
		 deleteNode(&envListHead, argv);
	ms->execute_code = exit_code;
}

static void	create_fork(pid_t *pid, int *status_code)
{
	*pid = fork();
	*status_code = 0;
	//g_global.in_fork = 1;
}

static void	call_nice(t_mini *mini, char *cmd, char **args, Node* envListHead, MyNode *varListHead)
{
	int	status_code;

	status_code = call_builtin(args, cmd, *mini->tokens, envListHead, varListHead);
	exit(status_code);
}


int	execute_builtin(char **argv, char *command, t_mini *ms, Node* envListHead, MyNode *varListHead)
{
	pid_t	pid;
	int		exit_code;
	printf("exit code\n");

	
	create_fork(&pid, &exit_code);
	if (pid == 0)
	{
		if (ms->pipe_write != -1)
		{
			close(ms->pipe_read);
			dup2(ms->pipe_write, STDOUT_FILENO);
		}

		call_nice(ms, command, argv, envListHead, varListHead);
	}
	else
	{	
		if (ms->pipe_read != -1)
		{
			
			dup2(ms->pipe_read, STDIN_FILENO);
			close(ms->pipe_write);
		}
		waitpid(pid, &exit_code, 0);
		//head = ft_create_list(head, NULL);
		//exit_code = call_builtin(argv, command, *ms->tokens, *l_env);
		post_call(argv, command,  ms, exit_code, envListHead, varListHead);
	}
	return (WEXITSTATUS(exit_code));
}
