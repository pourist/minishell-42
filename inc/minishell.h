/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:12:04 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/03/21 15:33:40 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "structs.h"
# define MALLOC_E 1
# define CMD_E 2
# define EXECV_E 3
# define METACHARS "()<>|&;"

extern int	g_sig;
// builtins
int			echo(char **args, int fd);
int			pwd(int fd);
int			cd(char **path, t_shell *sh);
int			env(t_env *env);
int			unset(t_shell *shell, char **args);
int			export(t_shell *shell, char **args);
// builtin Utils
t_env		**set_env_list(char **envp, char *argv_zero);
int			contains_char(char c, char *string);
t_env		*new_env_list(char *str);
int			print_export(t_env *env);
void		add_node_to_end(t_env **lst, t_env *new);
char		*ft_getenv(t_shell *sh, char *key);
// builtins
int			builtins(t_shell *sh, t_cmd *cmd);
int			echo(char **args, int fd);
int			pwd(int fd);
int			minishell_exit(char **args, t_shell *sh);
void		set_pwd_env(t_shell *sh, char *oldpwd);
// lexer
int			lexer(t_shell *sh);
char		split_on(char *input);
// parser
int			parser(t_shell *sh);
// executor
int			executor(t_shell *sh);
int			ft_execvp(t_shell *sh, t_cmd *cmd);
void		exec_path(t_list *lst, t_shell *sh);
int			builtins(t_shell *sh, t_cmd *cmd);

// free
int			free_cmd(t_shell *sh);
int			free_all(t_shell *sh);
int			free_pipe(t_pipe *pipe_s);
int			free_exit(t_shell *shell);
void		free_redlist(t_operation *op);

// errors
int			print_error(int type, t_shell *sh, char *str);
// utils
int			ft_arraylen(char **array);
char		*set_prompt(void);
int			verify_redirects(char **s);
int			reset_stds(t_shell *sh);
// signals
void		signal_setup(int pid);
// heredoc
int			start_heredoc(char *del, t_cmd *cmd, t_shell *sh);
int			heredoc_handle(t_cmd *cmd, t_shell *sh);
// pipe
int			do_pipe(t_list *lst, t_shell *sh);
// operation
int			execute_command(t_cmd *cmd, t_shell *sh);
t_operation	*red_parse(char **line);
int			handle_redir(t_cmd *cmd, t_shell *sgh);
// path
int			absolute_path_or_pwd(t_cmd *cmd);
void		update_path(t_shell *sh);
// void		add_spaces(char **str, int len);
#endif
