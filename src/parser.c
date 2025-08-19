/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:51:33 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 14:53:26 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*ft_getkey(char *s)
{
	char	*key;
	int		ctr;
	char	*s_copy;

	ctr = 1;
	if (s[0] == '$' && s[1] == '?')
		return (ft_strdup("$?"));
	if (s[0] == '$' && s[1] == '$')
	{
		print_error(99, NULL, "Warning: $$ env var not implemented");
		return (ft_strdup(""));
	}
	s_copy = ft_strdup(s);
	while (ft_isalnum(s_copy[ctr]) || 95 == s_copy[ctr])
		ctr++;
	s_copy[ctr] = 0;
	key = ft_strdup(s_copy);
	ft_freenull((void **)&s_copy);
	return (key);
}

static int	expand_envar(t_shell *sh, t_cmd *cmd, int i)
{
	int		ctr;
	char	*key;
	char	*val;

	ctr = -1;
	while (cmd->parsed[i][++ctr])
	{
		if (cmd->parsed[i][ctr] == 39)
		{
			ctr++;
			while (cmd->parsed[i][ctr] != 39 && cmd->parsed[i][ctr])
				ctr++;
		}
		else if (cmd->parsed[i][ctr] == 36 && cmd->parsed[i][ctr + 1])
		{
			key = ft_getkey(&cmd->parsed[i][ctr]);
			val = ft_getenv(sh, key);
			ft_strreplace(&cmd->parsed[i], key, val);
			ft_freenull((void **)&val);
			ft_freenull((void **)&key);
		}
	}
	return (1);
}

static int	expand_home(t_shell *sh, t_cmd *cmd, int i)
{
	if (ft_strcmp(cmd->parsed[i], "~"))
		return (1);
	ft_freenull((void **) &cmd->parsed[i]);
	cmd->parsed[i] = ft_strdup(ft_getenv(sh, "HOME"));
	return (1);
}

void	ft_strip(char **str)
{
	char	q;
	int		ctr;
	char	c;

	ctr = -1;
	q = 0;
	c = split_on(*str);
	while ((*str)[++ctr])
	{
		if (!q && ((*str)[ctr] == 39 || (*str)[ctr] == 34))
		{
			q = (*str)[ctr];
			(*str)[ctr] = c;
			while ((*str)[++ctr])
			{
				if ((*str)[ctr] == q)
				{
					(*str)[ctr] = c;
					q = 0;
					break ;
				}
			}
		}
	}
	ft_remove_c(str, c);
}

int	parser(t_shell *sh)
{
	t_list	*lst;
	t_cmd	*cmd;
	int		ctr;

	lst = *(sh->cmds);
	while (lst)
	{
		cmd = (t_cmd *)lst->content;
		ctr = -1;
		lst = lst->next;
		while ((cmd->parsed)[++ctr])
		{
			if (cmd->parsed[ctr] && !expand_envar(sh, cmd, ctr))
				return (0);
			if (cmd->parsed[ctr] && expand_home(sh, cmd, ctr))
				ft_strip(&(cmd->parsed)[ctr]);
		}
		cmd->op = red_parse(cmd->parsed);
		ft_freenull((void **)&cmd->parsed);
		cmd->parsed = cmd->op->command;
		heredoc_handle(cmd, sh);
	}
	return (1);
}
