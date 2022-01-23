/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:55:14 by vangirov          #+#    #+#             */
/*   Updated: 2022/01/23 18:46:07 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*td;
	unsigned char	*ts;

	if (dest == NULL && src == NULL)
		return (NULL);
	td = (unsigned char *)dest;
	ts = (unsigned char *)src;
	if (td < ts)
		while (n--)
			*td++ = *ts++;
	else
	{
		td = td + n - 1;
		ts = ts + n - 1;
		while (n--)
			*td-- = *ts--;
	}
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	rest;
	char	casted;

	casted = (char)c;
	rest = ft_strlen(str) + 1;
	while (rest > 0 && *str != casted)
	{
		rest--;
		str++;
	}
	if (rest)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(size);
	if (str == NULL)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - size + 1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	return_value;

	return_value = ft_strlen(src);
	if (size > 0)
	{
		while (size-- > 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (return_value);
}

///////////////////////////////////////////

// #include <stdio.h>
// int	main()
// {
// 	char	str[20] = "0123456789\nabcd";
// 	char	*tail;

// 	printf("%zu\n", sizeof(str));
// 	tail = ft_get_tail(str);
// 	printf("tail: %s\n", tail);
// 	printf("buff: %s\n", str);
// 	printf("%zu\n", sizeof(str));
// 	// printf("%s\n", ft_idxdup(str, 3));
// }