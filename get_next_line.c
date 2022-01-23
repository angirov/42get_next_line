/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:10:10 by vangirov          #+#    #+#             */
/*   Updated: 2022/01/23 14:18:04 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1 ////////////////////////////////////////////////////////

#include "get_next_line.h"

int		ft_read(int fd, char *buff, int size)
{
	int	rd;

	rd = read(fd, buff, size);
	if (rd < size)
		buff[rd] = '\0';
	return (rd);
}


// idx = ft_strchr_idx(buff, '\n');
// 		// printf("IDX: %d\n", idx);
// 		if (idx >= 0)
// 		{
// 			line = ft_join(line, ft_strdup_idx(buff, idx));
// 			ft_shift(buff, idx);
// 			// printf("ret line = %s\n", line);
// 			// printf("save buff = %s\n", buff);
// 			return (line);
// 		}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (ft_strchr_idx(buff, '\n') >= 0)
	{
		line = ft_strdup_idx(buff, ft_strchr_idx(buff, '\n')); //<<<<---------------------------------
		ft_shift(buff, ft_strchr_idx(buff, '\n'));
		return (line);
	}
	else if (*buff)
		line = ft_strdup_idx(buff, BUFFER_SIZE - 1); //<<<<---------------------------------
	while (ft_read(fd, buff, BUFFER_SIZE))
	{
		if (ft_strchr_idx(buff, '\n') >= 0)
		{
			line = ft_join(line, ft_strdup_idx(buff, ft_strchr_idx(buff, '\n'))); //<<<<---------------------------------
			ft_shift(buff, ft_strchr_idx(buff, '\n'));
			return (line);
		}
		else
			line = ft_join(line, ft_strdup_idx(buff, ft_strlen(buff))); //<<<<---------------------------------v
	}
	buff[0] = '\0';
	if (ft_strlen(line))
		return (line);
	return (NULL);
}

// #define BUFFER_SIZE 1

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	char	*ret;

	printf("===============================================================\n");
	fd = open("text", O_RDONLY);
	for (int i = 0; (ret = get_next_line(fd)) && i <= 40; i++)
	// while ((ret = get_next_line(fd)))
	{
		printf(">>>>>>>>>>>>>>>> %s\n", ret);
	}
}