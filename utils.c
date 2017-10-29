
#include "shell.h"

char	*ft_freedup(char *str, int f)
{
	int		l;
	char	*cpy;
	int		i;

	l = ft_strlen(str);
	if (!(cpy = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	if (f != 0)
		free(str);
	return (cpy);
}

void	ft_fre(char *str)
{
	free(str);
	str = NULL;
}

char	*ft_freejoin(char *s1, char *s2, int f)
{
	char	*s3;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(s3 = ft_strnew(l1 + l2 + 1)))
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcpy((s3 + l1), s2);
	s3[l1 + l2] = '\0';
	if (f == 1)
		ft_fre(s1);
	else if (f == 2)
		ft_fre(s2);
	else if (f == 3)
	{
		ft_fre(s1);
		ft_fre(s2);
	}
	return (s3);
}
