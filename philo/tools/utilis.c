/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahomari <ahomari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:15 by ahomari           #+#    #+#             */
/*   Updated: 2024/06/01 12:23:23 by ahomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_gettime(void)
{
	struct timeval	sp;

	if (gettimeofday(&sp, NULL) == -1)
		return (-1);
	return ((sp.tv_sec * 1000) + (sp.tv_usec / 1000));
}

void	ft_usleep(size_t time)
{
	size_t	new;

	new = ft_gettime();
	while (ft_gettime() - new < time)
		usleep(60);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	r;
	size_t			i;

	ptr = (unsigned char *)b;
	r = (unsigned char)c;
	i = 0;
	while (len > i)
	{
		ptr[i] = r;
		i++;
	}
	return ((void *)ptr);
}
