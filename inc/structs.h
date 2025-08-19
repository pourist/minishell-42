/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:26:51 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/18 17:13:55 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <signal.h>

typedef struct s_env_list	t_env;
typedef struct s_cmd		t_cmd;
typedef struct s_list		t_list;
typedef struct s_shell		t_shell;
typedef struct s_pipe		t_pipe;
typedef struct s_redlist	t_redlist;
typedef struct s_operation	t_operation;

typedef struct s_env_list
{
	char				*key;
	char				*value;
	int					include_env;
	struct s_env_list	*next;
}	t_env;

typedef enum e_redirection_type
{
	REDIRECT_OUT,
	REDIRECT_APPEND,
	REDIRECT_IN,
	REDIRECT_HEREDOC,
	NONE,
}	t_redirect_type;

typedef struct s_redlist
{
	char				*file_name;
	t_redirect_type		type;
	struct s_redlist	*next;
}	t_redlist;

typedef struct s_operation
{
	char				**command;
	t_redlist			*redir;
}	t_operation;

typedef struct s_cmd
{
	char			*raw;
	char			**parsed;
	int				fd;
	int				quote;
	int				heredoc[2];
	int				valid;
	int				pipe;
	pid_t			pid;
	t_operation		*op;
	int				exit_code;
}	t_cmd;

typedef struct s_shell
{
	char	*input;
	t_list	**cmds;
	t_env	**env;
	char	**paths;
	int		end;
	int		fd;
	char	*prompt;
	pid_t	child;
	int		exit_code;
	int		return_value;
	int		std_in;
	int		std_out;
}	t_shell;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_pipe
{
	int		cmnd_numb;
	int		pipe_number;
	int		*pipes;
	int		*pid;
}	t_pipe;
#endif
