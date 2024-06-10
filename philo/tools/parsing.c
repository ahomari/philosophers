/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:43:52 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/08 15:58:57 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int				i;
	int				n;
	unsigned long	r;

	(1) && (i = 0, n = 1, r = 0);
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		r = r * 10 +(str[i] - 48);
		if (((r * n) > INT_MAX))
			return (-1);
		i++;
	}
	return (r * n);
}

int	parsing(int ac, char **av)
{
	int	i;
	int	nbr;

	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (nbr < 0 || ft_strlen(av[i]) == 0)
		{
			msg_error(-1, "Error Invalid Arg!!\n");
			return (1);
		}
		i++;
	}
	return (0);
}
