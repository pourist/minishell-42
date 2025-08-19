/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:25:44 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 14:31:01 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_sig;

static void	sig_handle(int sig)
{
	char	*prompt;

	if (sig == SIGINT && !g_sig)
	{
		prompt = set_prompt();
		write(STDERR_FILENO, "\n", 1);
		rl_replace_line("", 0);
		write(STDERR_FILENO, prompt, ft_strlen(prompt));
		ft_freenull((void **)&prompt);
	}
	else if (sig == SIGINT && g_sig)
		write(STDERR_FILENO, "\n", 1);
}

static void	sig_handle_heredoc(int sig)
{
	g_sig = sig;
	rl_replace_line("", 0);
	write(STDERR_FILENO, "\n", 1);
	close(0);
}

void	signal_setup(int pid)
{
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (pid > 0)
	{
		signal(SIGINT, sig_handle);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (pid == -1)
	{
		signal(SIGINT, sig_handle_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
}
