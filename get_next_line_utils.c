#include <stdlib.h>
#include <stdio.h> ////////////////////////////////////////////////////////////

char	*my_idxdup(const char *s, int idx)
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

int	my_strlen(const char *s)
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

int	my_chridx(const char *str, int c)
{
	int	len;
	int	idx;
	char	casted;

	casted = (char)c;
	len = my_strlen(str);
	idx = 0;
	while (idx < len && str[idx] != casted)
	{
		idx++;
	}
	if (idx >= len)
		return (-1);
	return (idx);
}

void	my_shift(char *buff, int idx)
{
	int	len;
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

char	*my_join(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	if (!s1 || !s2)
		return (0);
	size = my_strlen(s1) + my_strlen(s2) + 1;
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
// #include <stdio.h>
// int	main()
// {
// 	char	str[20] = "0123456789";

// 	printf("%zu\n", sizeof(str));
// 	printf(">%s\n", str + 9);
// 	my_shift(str, 9);
// 	printf(">>%s\n", str);
// 	printf("%zu\n", sizeof(str));
// 	// printf("%s\n", my_idxdup(str, 3));
// }