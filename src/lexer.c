/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:57:43 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 13:34:00 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	split_on(char *input)
{
	char	c;

	c = 31;
	while (++c < 127)
	{
		if (!ft_strchr(input, c))
			break ;
	}
	return (c);
}

// single qoute = 39,  double quote = 34, pipe = 124, 92 = backslash
static int	check_quotes(char **s)
{
	int		single_q;
	int		double_q;
	int		i;
	char	placeholder;

	if (!ft_strchr(*s, 34) && !ft_strchr(*s, 39) && !ft_strchr(*s, 124))
		return (1);
	single_q = 0;
	double_q = 0;
	i = -1;
	placeholder = split_on(*s);
	while ((*s)[++i])
	{
		if ((*s)[i] == 34 && !single_q)
			double_q = !double_q;
		if ((*s)[i] == 39 && !double_q)
			single_q = !single_q;
		if ((*s)[i] == 124 && (!single_q && !double_q))
			(*s)[i] = placeholder;
		if (single_q && (*s)[i] == 92)
			ft_insert(s, 92, i++);
	}
	if (double_q || single_q)
		return (print_error(0, NULL, "closing quotes expected"));
	return (placeholder);
}

void	replace_unquoted(char **str, char c, int r)
{
	int		ctr;
	char	q;

	ctr = 0;
	while ((*str)[ctr])
	{
		if ((*str)[ctr] == 34 || (*str)[ctr] == 39)
		{
			q = (*str)[ctr];
			ctr++;
			while ((*str)[ctr] != q && (*str)[ctr])
				ctr++;
		}
		else if ((*str)[ctr] == c)
			(*str)[ctr] = r;
		ctr++;
	}
}

static t_list	**init_all_cmds(char **cmd_array)
{
	int		ctr;
	t_list	**all_cmds;
	t_cmd	*cmd;
	char	placeholder;

	ctr = 0;
	all_cmds = malloc(sizeof(t_list **));
	*all_cmds = NULL;
	while (cmd_array[ctr])
	{
		cmd = ft_calloc(1, sizeof(t_cmd));
		cmd->raw = cmd_array[ctr];
		placeholder = split_on(cmd_array[ctr]);
		replace_unquoted(&cmd_array[ctr], 32, placeholder);
		cmd->parsed = ft_split(cmd_array[ctr], placeholder);
		cmd->pipe = 1;
		ft_lstadd_back(all_cmds, ft_lstnew(cmd));
		ctr++;
	}
	return (all_cmds);
}

int	lexer(t_shell *sh)
{
	char	*input;
	char	**cmds;
	char	placeholder;

	input = ft_strtrim(sh->input, "	 ");
	if (!input)
		return (print_error(MALLOC_E, sh, NULL));
	if (!verify_redirects(&input) || ft_startswith(input, "|") || \
	ft_endswith(input, "|") || ft_endswith(input, ">") || \
	ft_endswith(input, "<"))
	{
		sh->exit_code = 1;
		return (print_error(99, sh, "Syntax error near unexpected token"));
	}
	placeholder = check_quotes(&input);
	if (!*input || !placeholder)
		return (0);
	cmds = ft_split(input, placeholder);
	if (!cmds)
		return (print_error(MALLOC_E, sh, NULL));
	sh->cmds = init_all_cmds(cmds);
	ft_freenull((void **)&sh->input);
	ft_freenull((void **)&cmds);
	sh->input = input;
	return (1);
}
