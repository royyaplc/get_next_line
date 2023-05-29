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

char	*get_next_line(int fd)
{
	static char	*stash[STASH_SIZE];
	char		*buf;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	
}
