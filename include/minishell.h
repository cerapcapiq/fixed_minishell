/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:48:55 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/25 17:02:49 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "linked_list.h"

// Token types
// builtin : builtin cmd: e.g. echo, cd
// cmd: any type of other command
// arg : any type of argument
// input : '<' 
// heredoc : '<<'
// trunc : '>'
// append : '>>'
// pipe : '|'

# define BUILTIN 1
# define CMD 2
# define ARG 3
# define INPUT 4
# define HEREDOC 5
# define TRUNC 6
# define APPEND 7
# define PIPE 8
# define ENV 9
# define VAR 11

# define PROMPT		0
# define EOT		100

// str - token string
// type - token type
// prev and next - linked list pointers to previous and next token

typedef struct Node {
    char* name;
    char* value;
    struct Node* next;
} Node;

typedef struct MyNode {
    char* name;
    char* value;
    struct MyNode* next;
} MyNode;

typedef struct s_token
{
	char			*str;
	int				type;
	int				quote;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_mini
{
	t_token		*tokens;
	int			cmd;
	int			pipe_read;
	int			pipe_write;
	int			input;
	int			output;
	int			stdin;
	int			stdout;
	int			execute_code;
	t_list		*env;
	Node* envListHead;
	MyNode*   varListHead;
}	t_mini;

typedef struct s_env
{
	char			*str;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;




/*typedef struct s_info
{
	int	g_exit_num;
}	t_info;

t_info	g_info;*/
//var
void var_insertNode(MyNode** head, char* name, char* value);

int				g_exit_num;
//init signals, pipes etc

extern char		**environ;
t_env *ft_list_added(t_env *l_env, char *str);
Node* getTerminalEnvList(char* env[]);
void freeList(Node* head);
char* getEnvValue(Node *envListHead, char* name);
void printList(Node* head);
//parser
void saveEnvironmentToStruct(t_env* env_head);
void freeEnvironmentStruct(t_env* env_head);
void			ft_whitespace(char *buff);
char			*display_readline(char *input);
int				ft_strcmp(char *s1, char *s2);
void			print_tokens(t_token *tokens);
int				builtin_cmd(char *token);
int				delim_token(char *token);
int				token_type(t_mini *mini, char *token);
t_token			*new_token(t_mini *mini, char *data);
void			token_addend(char *data, t_mini *mini);
int				create_pipe(t_mini *mini);
int				redirect_output(t_mini *ms, t_token *token, int type);
int				redirect_input(t_mini *ms, t_token *token);

void	parse(t_mini *mini, char *buff, Node* envListHead, MyNode *varListHead);
int findSubstring(const char* string, const char* substring);

struct s_node	*ft_link_env(void);
struct s_node	*delete_var(char *lineptr, struct s_node *head_ref);
void var_freeList(MyNode* head);

//execue
int				count_argc(char **args);
void			call_pipe_redirect(t_mini *mini, t_token *command,
					t_token *tok);
void			here_doc_input(t_token *command, int pid);
char			**convert_argv(t_token	*tokens);

int	call_builtin(char **argv, char *command, t_token token, Node* envListHead, MyNode* varListHead);

int	execute_builtin(char **argv, char *command, t_mini *ms, Node* envListHead, MyNode *varListHead);
int				ft_cmd(char *str, char *lineptr);
int				getenv_cmd(int argc, char **argv);
char			*traverse_dir(char *path, char *exe);
int	call_cmd(char **av, Node *envListHead);

int	execute(t_mini *mini, Node* envListHead, MyNode *varListHead);
int				ft_clear_data(char *data);
int				it_works(char *cmd_path);
void			check_heredoc(char **argv);
//int				ft_ex(char **argv, char **envp, int i);

//builtin_commands
int				echo(int argc, char **argv, t_token curr);
int				pwd(void);
int				mini_exit(char **argv);
int				cd(int argc, char **argv);
void			ft_home_dir(void);
void			ft_prev_dir(char *path);
void			ft_unset(char **str);

void	ft_export(char **str, Node* envListHead);
void insertNode(Node** head, char* name, char* value);

//int ft_var(char *argv, struct s_node *head);

struct s_linked	*ft_linked_list(char *cpy);
char **ft_getenv(Node *envListHead);
int				for_env(char *token);
char			*get_name(char *linestr);
void deleteNode(Node** head, char** name);

int				ft_var(char **argv);
struct s_node	*ft_add_back(struct s_node *head_ref, char *cpy);
int				show_var(char *lineptr, struct s_node *head);
char			*ft_var_content(char *lineptr, struct s_node *head);
char			*get_arg_content(char *lineptr);
char			*ft_add_var_content(char *lineptr, struct s_linked *head);

char	*get_the_new_var(char *lineptr, t_env *l_env);
char			*strremove(char *str, const char *sub);
void			moving_the_s_node(char *str);

struct s_node	*ft_var_main(char *argv, struct s_node *head);
struct s_node	*create_list(struct s_node **head_ref, char *lineptr);
struct s_linked	*ft_create_list(struct s_linked **head, char *str);
struct s_node	*display_s_node(struct s_node *head_ref);
struct s_linked	*creates_node(void);
struct s_linked	*adds_node(struct s_node head, char *value);
struct s_linked	*add_to_var(char *str, struct s_linked **head);
void display_linked_s_node(t_env *l_env);

//quote
int				ft_detect_quote(char *data);
int				closed_dub_quote(char *line);
int				ft_dollar(char *new);
int				detect_q(char *data);
int				ft_detect_dollar(char	*s1);
char			*ft_delete_quote(char *data);
int				closed_quote(char *line);
int				ft_dollar_sign(char *str);
int				ft_double_detect_quote(char *data);

//signal
void			define_signal(void);
void			disable_veof(void);

//free
void			token_free(t_token *tok);
void			agrv_free(char **argv);
void			ft_error_exit(int g_exit_num);
void			ft_error(int err_num);

#endif
