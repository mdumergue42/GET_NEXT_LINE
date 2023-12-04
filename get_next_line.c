/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:51:12 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/04 14:53:20 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_end_of_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	
	while (!buffer[i] && !line[i])
	{
		if (ft_end_of_line(line) == 1)
			return (line);
		read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		i++;
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
    int    fd = open("test.txt", O_RDONLY);
    char *line;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
    	free(line);
	}
}
