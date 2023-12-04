/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:51:12 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/04 14:02:12 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_end_of_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
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
	int			rd;
	char	*line;

	line = ft_calloc(1, 1);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (ft_end_of_line(line) == 1)
		return (line);
	line = ft_strjoin(line, buffer);
	rd = read(fd, buffer, BUFFER_SIZE);	
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int    fd = open("test.txt", O_RDONLY);
    char *line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //line = get_next_line(fd);
    //printf("/%s", line);
    //free(line);
    //printf("%s", get_next_line(fd));
}