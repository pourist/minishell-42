/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:56:04 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/21 14:51:39 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	absolute_path_or_pwd(t_cmd *cmd)
{
	char	*tmp_cmd;
	char	*tmp_cwd;
	char	*program;
	char	*cwd;

	program = cmd->parsed[0];
	if (ft_startswith(program, "/"))
		return (1);
	if (ft_startswith(program, "./") || ft_startswith(program, "../"))
	{
		cwd = getcwd(NULL, 0);
		tmp_cwd = ft_strjoin(cwd, "/");
		ft_freenull((void **)&cwd);
		cwd = tmp_cwd;
		tmp_cmd = ft_strjoin(cwd, program);
		ft_freenull((void **)&cwd);
		ft_freenull((void **)&program);
		cmd->parsed[0] = tmp_cmd;
		return (1);
	}
	return (0);
}

void	update_path(t_shell *sh)
{
	char	*all_paths;
	int		ctr;

	ctr = -1;
	if (sh->paths)
	{
		while (sh->paths[++ctr])
			ft_freenull((void **)&sh->paths[ctr]);
		ft_freenull((void **)&sh->paths);
	}
	all_paths = ft_getenv(sh, "PATH");
	if (!ft_strcmp(all_paths, ""))
		sh->paths = NULL;
	else
		sh->paths = ft_split(all_paths, ':');
	ft_freenull((void **)&all_paths);
}
