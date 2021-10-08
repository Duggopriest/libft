#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		a;

	str = malloc(len * sizeof(char));
	i = 0;
	a = ft_strlen(s);
	if (str == NULL)
		return (NULL);
	while (len > 0 && i < a)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
