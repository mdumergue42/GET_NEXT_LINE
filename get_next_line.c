/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:51:12 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/04 12:12:44 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_end_of_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		ft_strdup(str[i]);
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			rd;
	char	*line;

	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (BUFFER_SIZE != '\n')
	{
		rd = read(fd, buffer, BUFFER_SIZE);

	}
	line = ft_end_of_line(line);
}