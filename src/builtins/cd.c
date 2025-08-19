/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:14:12 by ppour-ba          #+#    #+#             */
/*   Updated: 2024/03/20 18:22:47 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	cd_error(char *path)
{
	char	*error;

	error = ft_strjoin("cd: ", strerror(errno));
	if (path)
		print_error(99, NULL, error);
	else
		print_error(99, NULL, error);
	ft_freenull((void **)&error);
	return (1);
}

static int	cd_path(char *path, t_shell *sh)
{
	char	*temp;
	char	*temp_path;

	if (!ft_strncmp(path, "~/", 2))
		temp_path = ft_strjoin(getenv("HOME"), path + 1);
	else
		temp_path = path;
	temp = getcwd(NULL, 0);
	if (chdir(temp_path) != 0)
	{
		if (!ft_strncmp(path, "~/", 2))
			free(temp_path);
		ft_freenull((void **)&temp);
		return (cd_error(path));
	}
	else
		set_pwd_env(sh, temp);
	if (!ft_strncmp(path, "~/", 2))
		free(temp_path);
	ft_freenull((void **)&temp);
	return (0);
}

static int	cd_back(t_shell *sh)
{
	char	*temp;
	char	*oldpwd;

	temp = getcwd(NULL, 0);
	oldpwd = ft_getenv(sh, "OLDPWD");
	if (!*oldpwd)
	{
		ft_freenull((void **)&oldpwd);
		ft_freenull((void **)&temp);
		return (print_error(99, sh, "cd: OLDPWD not set"));
	}
	else if (chdir(oldpwd) != 0)
	{
		ft_freenull((void **)&temp);
		ft_freenull((void **)&oldpwd);
		return (cd_error(NULL));
	}
	else
		set_pwd_env(sh, temp);
	ft_freenull((void **)&temp);
	ft_freenull((void **)&oldpwd);
	return (pwd(0));
}

static int	cd_home(t_shell *sh)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (chdir(getenv("HOME")) != 0)
	{
		ft_freenull((void **)&temp);
		return (cd_error(NULL));
	}
	else
		set_pwd_env(sh, temp);
	ft_freenull((void **)&temp);
	return (0);
}

int	cd(char **path, t_shell *sh)
{
	if (ft_arraylen(path) > 2)
	{
		print_error(0, sh, "cd: too many arguments");
		return (1);
	}
	if (path[1] == NULL || ft_strcmp(path[1], "~") == 0)
		return (cd_home(sh));
	else if (ft_strncmp(path[1], "-", 2) == 0)
		return (cd_back(sh));
	else
		return (cd_path(path[1], sh));
}
