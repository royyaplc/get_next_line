/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:02:10 by lyap              #+#    #+#             */
/*   Updated: 2023/05/29 13:26:19 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
*/

#include "get_next_line.h"

void	ft_read_line(char *stash, char *line)
{
	
}

int	ft_read_file(int fd, char *buffer, char *stash, char *line)
{
	int		bytes_read;
	int		new_line;
	
	bytes_read = 1;
	new_line = ft_strchr(stash, '\n');
	while (bytes_read && !new_line)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free_ptr(buffer);
	ft_read_line(stash, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup_gnl("");
	if (ft_read_file(fd, buffer, stash, line) == 0 && *line == '\0')
	{
		free_ptr(line);
		return (NULL);
	}
	return (line);
}
