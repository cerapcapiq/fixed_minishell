/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasarud <abasarud@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:15:45 by abasarud          #+#    #+#             */
/*   Updated: 2023/05/23 12:20:46 by abasarud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//void create_pipe(char *command1[], char *command2[])

// int create_pipe(t_mini *mini) {
//     int pipefd[2];
//     pid_t pid1, pid2;

//     // Create a pipe
//     if (pipe(pipefd) == -1) {
//         perror("Pipe creation failed");
//         exit(EXIT_FAILURE);
//     }

//     // Fork the first command
//     pid1 = fork();
//     if (pid1 == -1) {
//         perror("Fork failed");
//         exit(EXIT_FAILURE);
//     }

//     if (pid1 == 0) {
//         // Child process - execute the first command and redirect output to the pipe
//         close(pipefd[0]); // Close the unused read end of the pipe
//         dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the pipe
//         close(pipefd[1]); // Close the write end of the pipe

//        // execvp(command1[0], command1); // Execute the first command
//         perror("Execution of command 1 failed");
//         exit(EXIT_FAILURE);
//     }

//     // Fork the second command
//     pid2 = fork();
//     if (pid2 == -1) {
//         perror("Fork failed");
//         exit(EXIT_FAILURE);
//     }

//     if (pid2 == 0) {
//         // Child process - execute the second command and read input from the pipe
//         close(pipefd[1]); // Close the unused write end of the pipe
//         dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to the pipe
//         close(pipefd[0]); // Close the read end of the pipe

//       //  execvp(command2[0], command2); // Execute the second command
//         perror("Execution of command 2 failed");
//         exit(EXIT_FAILURE);
//     }

//     // Parent process - close pipe file descriptors and wait for child processes to finish
//     close(pipefd[0]);
//     close(pipefd[1]);
//     waitpid(pid1, NULL, 0);
//     waitpid(pid2, NULL, 0);
// // 	return 0;
// }

int	create_pipe(t_mini *mini)
{
	int		fd[2];
	int		status;

	status = pipe(fd);
	if (status < 0)
	{
		mini->pipe_read = -1;
		mini->pipe_write = -1;
		return (0);
	}
	mini->pipe_read = fd[0];
	mini->pipe_write = fd[1];
	return (1);
}