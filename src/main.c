/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:32:23 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 16:14:10 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_sig;

void	init_prompt(t_shell *sh)
{
	if (g_sig == SIGINT)
		sh->exit_code = 130;
	g_sig = 0;
	if (sh->input)
		ft_freenull((void **)&sh->input);
	sh->input = readline(sh->prompt);
	if (!sh->input)
	{
		minishell_exit(NULL, sh);
		return ;
	}
	if (*(sh->input))
	{
		add_history(sh->input);
		if (!lexer(sh))
			return ;
		if (!parser(sh))
			return ;
		if (!sh->input)
			return ;
		if (!executor(sh))
			return ;
		free_cmd(sh);
	}
}

t_shell	*init_shell(int argc, char **envp, char *argv_zero)
{
	t_shell	*new;

	if (argc != 1)
	{
		write(2, "Usage: ./minishell\n", 20);
		exit (1);
	}
	new = malloc(sizeof(t_shell));
	if (!new)
		return (NULL);
	new->env = set_env_list(envp, argv_zero);
	new->end = 0;
	new->exit_code = 0;
	new->cmds = NULL;
	new->input = NULL;
	new->fd = 1;
	new->paths = NULL;
	new->return_value = 0;
	new->prompt = set_prompt();
	new->std_in = dup(0);
	new->std_out = dup(1);
	return (new);
}

int	free_exit(t_shell *shell)
{
	int	ret;

	ret = shell->exit_code;
	free_all(shell);
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	g_sig = 0;
	signal_setup(1);
	shell = init_shell(argc, envp, argv[0]);
	if (!shell)
		return (print_error(MALLOC_E, shell, NULL));
	while (!shell->end)
		init_prompt(shell);
	return (free_exit(shell));
}
