#include "libft.h"

static int	cp(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

int	wl(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	*strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	**ft_split(char const *s, char t)
{
	int		a;
	size_t	b;
	size_t	c;
	char	**str;

	a = -1;
	b = 0;
	str = (char **)malloc(sizeof(*str) * (cp(s, t) + 1));
	if (str == NULL || !s)
		return (NULL);
	while (++a < cp(s, t))
	{
		c = 0;
		str[a] = strnew(wl(&s[b], t) + 1);
		if (str[a] == NULL)
			return (NULL);
		while (s[b] == t)
			b++;
		while (s[b] != t && s[b])
			str[a][c++] = s[b++];
		str[a][c] = '\0';
	}
	str[a] = '\0';
	return (str);
}