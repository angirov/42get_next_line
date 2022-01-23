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

int	ft_strchr_idx(const char *str, int c)
{
	int	len;
	int	idx;
	char	casted;

	casted = (char)c;
	len = ft_strlen(str);
	idx = 0;
	while (idx < len && str[idx] != casted)
	{
		idx++;
	}
	if (idx >= len)
		return (-1);
	return (idx);
}

void	ft_shift(char *buff, int idx)
{
	int	i;

	i = 0;
	while (buff[idx + 1 + i])
	{
		buff[i] = buff[idx + 1 + i];
		i++;
	}
	while (buff[i])
	{
		buff[i] = '\0';
		i++;
	}
}

// char	*ft_join(char *s1, char const *s2)
// {
// 	size_t	size;
// 	char	*str;

// 	if (!s1 || !s2)
// 		return (0);
// 	size = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	str = (char *)malloc(size);
// 	if (str == NULL)
// 		return (NULL);
// 	while (*s1)
// 		*str++ = *s1++;
// 	free(s1);
// 	while (*s2)
// 		*str++ = *s2++;
// 	*str = '\0';
// 	return (str - size + 1);
// }

char	*ft_join(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strdup_idx(const char *s, int idx)
{
	char	*dup;
	int	i;

	dup = (char *)malloc(idx + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < idx)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h>
// int	main()
// {
// 	char	str[20] = "0123456789";

// 	printf("%zu\n", sizeof(str));
// 	printf(">%s\n", str + 9);
// 	ft_shift(str, 9);
// 	printf(">>%s\n", str);
// 	printf("%zu\n", sizeof(str));
// 	// printf("%s\n", ft_idxdup(str, 3));
// }