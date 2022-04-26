#include "libft.h"

static int	count_parts(char const *str, char c)
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

int	word_lenght(char const *s, char c)
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

char	**ft_split(char const *s, char t)
{
	int		line;
	size_t	b;
	size_t	c;
	char	**str;

	line = -1;
	b = 0;
	str = (char **)malloc(sizeof(*str) * (count_parts(s, t) + 1));
	if (str == NULL || !s)
		return (NULL);
	while (++line < count_parts(s, t))
	{
		c = 0;
		str[line] = malloc(word_lenght(&s[b], t) + 1);
		if (str[line] == NULL)
			return (NULL);
		while (s[b] == t)
			b++;
		while (s[b] != t && s[b])
			str[line][c++] = s[b++];
		str[line][c] = '\0';
	}
	str[line] = 0;
	return (str);
}
