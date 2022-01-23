/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:35:36 by vangirov          #+#    #+#             */
/*   Updated: 2022/01/23 11:16:44 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_read(int fd, char *buff, int size);

char	*ft_strdup_idx(const char *s, int idx);
int		ft_strlen(const char *s);
int		ft_strchr_idx(const char *str, int c);
void	ft_shift(char *buff, int idx);
char	*ft_join(char *s1, char const *s2);

#endif