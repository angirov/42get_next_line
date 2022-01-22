/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:10:10 by vangirov          #+#    #+#             */
/*   Updated: 2022/01/22 21:18:01 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1
#include <stdlib.h> ////////////////////////////////////////////////////////////
#include <unistd.h> ////////////////////////////////////////////////////////////
#include <stdio.h> ////////////////////////////////////////////////////////////

char	*my_idxdup(const char *s, int idx);
int		my_strlen(const char *s);
int		my_chridx(const char *str, int c);
void	my_shift(char *buff, int idx);
char	*my_join(char const *s1, char const *s2);

int		my_read(int fd, char *buff, int size)
{
	int	rd;

	rd = read(fd, buff, size);
	if (rd < size)
		buff[rd] = '\0';
	return (rd);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	int			idx;
	char		*line;

	idx = my_chridx(buff, '\n');
	if (idx >= 0)
	{
		line = my_idxdup(buff, idx);
		my_shift(buff, idx);
		return (line);
	}
	else if (*buff)
		line = my_idxdup(buff, BUFFER_SIZE - 1);
	while (my_read(fd, buff, BUFFER_SIZE))
	{
		// printf("read into buffer: %s [%d]\n", buff, my_strlen(buff));
		idx = my_chridx(buff, '\n');
		// printf("IDX: %d\n", idx);
		if (idx >= 0)
		{
			line = my_join(line, my_idxdup(buff, idx));
			my_shift(buff, idx);
			// printf("ret line = %s\n", line);
			// printf("save buff = %s\n", buff);
			return (line);
		}
		else
			line = my_join(line, my_idxdup(buff, my_strlen(buff)));
			// if (my_strlen(buff) < BUFFER_SIZE)
			// 	return (line);
			// printf("line = %s\n", line);
	}
	buff[0] = '\0';
	if (my_strlen(line))
		return (line);
	return (NULL);
}

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	int	fd;
	int	rd;
	char	*ret;

	printf("===============================================================\n");
	fd = open("text", O_RDONLY);
	for (int i = 0; (ret = get_next_line(fd)) && i <= 40; i++)
	// while ((ret = get_next_line(fd)))
	{
		printf(">>>>>>>>>>>>>>>> %s\n", ret);
	}
}