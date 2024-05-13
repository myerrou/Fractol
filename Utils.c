#include "Fractol.h"

void	putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

double	ft_atof(const char *str, long in, double frac)
{
	double	nbr;
	int		s;

	s = +1;
	nbr = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			s = -s;
	while (*str != '.' && *str)
		in = (in * 10) + (*str++ - 48);
	if (*str == '.')
		++str;
	while (*str)
	{
		nbr /= 10;
		frac = frac + (*str++ - 48) * nbr;
	}
	return (s * (in + frac));
}


int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	s_check(const char *str)
{
	int i = 0;

	while (str[i] == ' ')
		i++;
	if (str[i] == '.' || !str[i])
		return (0);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (str[i] == '.')
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	if (str[i] == '.')
		i++;
	else
		return (0);
	if (!str[i])
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i])
		return (1);
	return (0);
}
