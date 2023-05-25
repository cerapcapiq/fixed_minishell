/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:14:52 by abasarud          #+#    #+#             */
/*   Updated: 2023/04/12 18:18:40 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//ctrl c = sigint (intrrup process) ---> new prompt  || done!
//ctrl \ = sigquit (quit process) ---->nothing   |||done!
//ctrl z = sigstp ()
//ctrl d = eof --> exit || done!

void	sig_handler(int signum)
{
	printf("%d done", signum);
}

/*static void	int_handler(void)
{
	printf("\n"); // Move to a new line
	rl_on_new_line(); // Regenerate the prompt on a newline
   // rl_replace_line(" ", 0); // Clear the previous text
   rl_redisplay();
}*/

void	disable_veof(void)
{
	struct termios	ori_settings;
	struct termios	new_settings;

	tcgetattr(STDIN_FILENO, &ori_settings);
	new_settings = ori_settings;
	new_settings.c_cc[VEOF] = 4;
	new_settings.c_cc[VINTR] = 3;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

void	define_signal(void)
{
	disable_veof();
	signal(SIGQUIT, SIG_IGN);
}
