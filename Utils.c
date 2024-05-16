/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerrou <myerrou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:03:18 by myerrou           #+#    #+#             */
/*   Updated: 2024/05/16 15:07:40 by myerrou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	write(2, NC, 2);
}

double	ft_atof(const char *str, long in, double frac)
{
	double	nbr;
	int		s;
	int		i;

	s = 1;
	i = 0;
	nbr = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			s = -s;
	while (str[i] != '.' && str[i])
		in = (in * 10) + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		nbr /= 10;
		frac = frac + (str[i++] - 48) * nbr;
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

int	s_check(const char *str, int i)
{
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
