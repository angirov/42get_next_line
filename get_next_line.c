/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:10:10 by vangirov          #+#    #+#             */
/*   Updated: 2022/01/23 21:56:24 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define BUFFER_SIZE 10 ////////////////////////////////////////////////////////
// #include <stdio.h> ////////////////////////////////////////////////////////

#include "get_next_line.h"
char	*ft_get_tail(char *buff)
{
	int		len;
	char	*tail;
	char	*rest;

	rest = ft_strchr(buff, '\n');
	if (!rest)
		return (buff);
	rest++;
	len = rest - buff;
	tail = (char *)malloc(sizeof(char) * len + 1);
	ft_strlcpy(tail, buff, len + 1);
	len = ft_strlen(rest);
	ft_memmove(buff, rest, len + 1);
	return (tail);
}

int		ft_read(int fd, char *buff, int size)
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
	char		*tail;
	int			rd;

	if (fd < 0)
		return (NULL);
	line = (char *)malloc(1);
	line[0] = '\0';
	while (!ft_strchr(buff, '\n'))
	{
		line = ft_concat(line, buff);
		rd = ft_read(fd, buff, BUFFER_SIZE);
		// printf("buff: %s\n", buff); ////////////////////////////////////////////////////////
		// printf("rd: %d\n", rd); ////////////////////////////////////////////////////////
		if (rd && rd < BUFFER_SIZE)
		{
			// printf("breaking\n"); ////////////////////////////////////////////////////////
			break ;
		}
		if (!rd)
			return (NULL);
	}
	// printf("buff: %s\n", buff); ////////////////////////////////////////////////////////
	tail = ft_get_tail(buff);
	// printf("tail: %s\n", tail); ////////////////////////////////////////////////////////
	// printf("line: %s\n", line); ////////////////////////////////////////////////////////
	line = ft_concat(line, tail);
	// printf("line: %s\n", line); ////////////////////////////////////////////////////////
	if (buff != tail)
		free(tail);
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
// 	for (int i = 0; (ret = get_next_line(fd)) && i <= 22; i++)
// 	// while ((ret = get_next_line(fd)))
// 	{
// 		printf(">>>>>>>>>>>>>>>> %s", ret);
// 	}
// }