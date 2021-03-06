/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:14:42 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/15 13:29:23 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_tail(char *line, char *buff)
{
	int		len;
	char	*tail;
	char	*rest;

	rest = ft_strchr(buff, '\n');
	if (!rest)
		return (ft_concat(line, buff));
	rest++;
	len = rest - buff;
	tail = (char *)malloc(sizeof(char) * len + 1);
	ft_strlcpy(tail, buff, len + 1);
	len = ft_strlen(rest);
	ft_memmove(buff, rest, len + 1);
	line = ft_concat(line, tail);
	free(tail);
	return (line);
}

int	ft_read(int fd, char *buff, int size)
{
	int	rd;

	rd = read(fd, buff, size);
	buff[rd] = '\0';
	return (rd);
}

char	*ft_concat(char *line, char *nonl_buff)
{
	char	*newline;

	newline = ft_strjoin(line, nonl_buff);
	free(line);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		rd;

	if (fd < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char));
	line[0] = 0;
	while (!ft_strchr(buff, '\n'))
	{
		line = ft_concat(line, buff);
		rd = ft_read(fd, buff, BUFFER_SIZE);
		if (rd == 0 && line[0])
			break ;
		if (rd <= 0)
			{
				free(line);
				return (NULL);
			}
	}
	line = ft_get_tail(line, buff);
	return (line);
}

// #define BUFFER_SIZE 1

// #include <fcntl.h>
// #include <stdio.h>

// int	main()
// {
// 	int		fd;
// 	char	*ret;

// 	printf("===============================================================\n");
// 	fd = open("text", O_RDONLY);
// 	// for (int i = 0; (ret = get_next_line(fd)) && i <= 22; i++)
// 	while ((ret = get_next_line(fd)))
// 	{
// 		printf(">>>>>>>>>>>>>>>> %s", ret);
// 		free(ret);
// 	}
// 	free(ret);
// 	close(fd);
// 	return (0);
// }