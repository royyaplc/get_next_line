/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:17:48 by lyap              #+#    #+#             */
/*   Updated: 2023/05/29 13:18:55 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
