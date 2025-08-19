/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:45:26 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/02/21 15:08:24 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_first_read(int fd, char **rest, ssize_t *bytes_read)
{
	if (!(*rest) || !(**rest))
	{
		if (*rest)
			free(*rest);
		(*rest) = malloc(BUFFER_SIZE + 1);
		if (!(*rest))
			return ;
		*bytes_read = read(fd, (*rest), BUFFER_SIZE);
		if (*bytes_read <= 0)
		{
			free((*rest));
			*rest = NULL;
			return ;
		}
		(*rest)[*bytes_read] = '\0';
	}
}

static char	*_handle_no_nl(char **rest)
{
	size_t	nl_idx;

	if (ft_strchr(*rest, '\n'))
	{
		nl_idx = ft_strchr(*rest, '\n') - *rest;
		return (ft_substr(*rest, 0, nl_idx + 1));
	}
	else if (ft_strchr(*rest, '\0'))
		return (ft_strdup(*rest));
	else
		return (NULL);
}

static char	*_get_nl(int fd, char **rest, ssize_t *bytes_read)
{
	char	*tmp;
	char	*buffer;

	while (!ft_strchr(*rest, '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read <= 0)
		{
			free(buffer);
			if (*bytes_read == 0)
				return (_handle_no_nl(rest));
			free(*rest);
			return (NULL);
		}
		buffer[*bytes_read] = '\0';
		tmp = ft_strjoin(*rest, buffer);
		free(*rest);
		free(buffer);
		*rest = tmp;
	}
	return (_handle_no_nl(rest));
}

int	_handle_rest(char **rest)
{
	size_t	nl_idx;
	char	*tmp;

	if (ft_strchr((*rest), '\n'))
	{
		nl_idx = (size_t)(ft_strchr((*rest), '\n') - (*rest));
		tmp = ft_strdup(((*rest) + nl_idx + 1));
		if (!tmp)
			return (0);
		free((*rest));
		(*rest) = tmp;
		return (1);
	}
	free(*rest);
	*rest = NULL;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*nl;
	ssize_t		bytes_read;

	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free (rest);
		rest = NULL;
		return (NULL);
	}
	bytes_read = 0;
	_first_read(fd, &rest, &bytes_read);
	if (!rest)
		return (NULL);
	nl = _get_nl(fd, &rest, &bytes_read);
	if (!nl)
		return (NULL);
	if (!_handle_rest(&rest))
		return (NULL);
	return (nl);
}
