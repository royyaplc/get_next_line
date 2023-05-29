/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyap <lyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:04:34 by lyap              #+#    #+#             */
/*   Updated: 2023/05/29 13:41:29 by lyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// INCLUDES //
# include <unistd.h>
# include <stdlib.h>

// DEFINES //
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef STASH_SIZE
#  define STASH_SIZE 1024
# endif

// PROTOTYPES //
char	*get_next_line(int fd);

#endif