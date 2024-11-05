/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:51:12 by madumerg          #+#    #+#             */
/*   Updated: 2024/11/05 20:35:48 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_end_of_line(char *line, char *buffer)
{
	int	i;
	int	j;

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
	static char	*buffer;
	char		*line;
	int			read_nb;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (buffer && line)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (ft_end_of_line(line, buffer) == 1)
			return (line);
		read_nb = read(fd, buffer, BUFFER_SIZE);
		if (read_nb < 1)
			return (ft_verif(&buffer, line));
		buffer[read_nb] = '\0';
	}
	return (NULL);
}

/*#include <stdio.h>
#include <fcntl.h>

int    main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);

    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
	if (fd > 0)
		close(fd);
    return (0);
}*/
