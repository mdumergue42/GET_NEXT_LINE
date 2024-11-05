/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:51:12 by madumerg          #+#    #+#             */
/*   Updated: 2024/11/05 20:36:10 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	ft_end_of_line(char *line, char *buffer)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		i++;
		while (line[i])
		{
			buffer[j] = line[i];
			i++;
			j++;
		}
		buffer[j] = '\0';
		line[i - j] = '\0';
		return (1);
	}
	return (0);
}

char	*ft_verif(char **buffer, char *line)
{
	free(*buffer);
	*buffer = NULL;
	if (line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			read_nb;

	line = ft_calloc(1, 1);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (buffer[fd] && line)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (NULL);
		if (ft_end_of_line(line, buffer[fd]) == 1)
			return (line);
		read_nb = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_nb < 1)
			return (ft_verif(&buffer[fd], line));
		buffer[fd][read_nb] = '\0';
	}
	return (NULL);
}

/*#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;

	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	int i = 0;
	while (i < 10)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
