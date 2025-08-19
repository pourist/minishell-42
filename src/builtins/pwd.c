/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:33:30 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/19 19:09:33 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	set_pwd_env(t_shell *sh, char *oldpwd)
{
	char	*str[3];

	str[0] = "";
	str[1] = ft_strjoin ("PWD=", getcwd(NULL, 0));
	str[2] = NULL;
	export(sh, str);
	ft_freenull((void **)&str[1]);
	str[1] = ft_strjoin ("OLDPWD=", oldpwd);
	export(sh, str);
	ft_freenull((void **)&str[1]);
}

int	pwd(int fd)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		ft_putendl_fd(cwd, fd);
		ft_freenull((void **)&cwd);
		return (0);
	}
	else
	{
		perror("error");
		return (1);
	}
}
