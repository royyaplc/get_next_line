/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:02:10 by lyap              #+#    #+#             */
/*   Updated: 2023/06/03 17:26:06 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
*/

//#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup_gnl(const char *str)
{
	char	*target;
	size_t	i;

	target = malloc(sizeof(char) * ft_strlen_gnl(str) + 1);
	if (target == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		target[i] = str[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen_gnl(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if (!size)
	{
		if (!dest)
			return (0);
		else
			return (ft_strlen_gnl(src));
	}
	dest_len = ft_strlen_gnl(dest);
	src_len = ft_strlen_gnl(src);
	i = 0;
	if (dest_len >= size)
		return (src_len + size);
	while (src[i] && (dest_len + i + 1) < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen_gnl(s) < start)
		return (ft_strdup_gnl(""));
	str_len = ft_strlen_gnl(s + start);
	if (str_len < len)
		len = str_len;
	substr = malloc((sizeof(char)) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy_gnl(substr, s + start, len + 1);
	return (substr);
}

int	ft_check_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len;

	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	joined = malloc((sizeof(char)) * (len + 1));
	if (joined == NULL)
		return (NULL);
	ft_strlcpy_gnl(joined, s1, ft_strlen_gnl(s1) + 1);
	ft_strlcat_gnl(joined, s2, len + 1);
	return (joined);
}

char	*ft_buffer_balance(char *stash, int *nl_pos)
{
	char	*balance;

	balance = ft_substr_gnl(stash, *nl_pos + 1,
			(ft_strlen_gnl(stash) - *nl_pos - 1));
	return (balance);
}

char	*ft_extract_line(char *stash, int *nl_pos)
{
	char	*line;

	while (stash[*nl_pos] && stash[*nl_pos] != '\n')
		*nl_pos = *nl_pos + 1;
	line = ft_substr_gnl(stash, 0, *nl_pos);
	if (ft_strlen_gnl(stash) != (unsigned long)*nl_pos)
		line[*nl_pos] = '\n';
	line[*nl_pos + 1] = '\0';
	return (line);
}

char	*ft_read_to_buffer(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read != 0 && ft_check_nl(stash) < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			nl_pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup_gnl("");
	stash = ft_read_to_buffer(fd, stash);
	if (!stash)
		return (NULL);
	nl_pos = 0;
	line = ft_extract_line(stash, &nl_pos);
	stash = ft_buffer_balance(stash, &nl_pos);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("tests/test.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("line 1: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("line 2: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("line 3: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("line 4: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("line 5: %s", line);
	free(line);
	line = get_next_line(fd1);
	printf("line 6: %s", line);
	free(line);
	return (0);
}