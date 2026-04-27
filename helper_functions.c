/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:02:37 by karmanz           #+#    #+#             */
/*   Updated: 2026/04/27 14:35:44 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long   get_time(void)
{
    struct timeval  tv;

    if (gettimeofday(&tv, NULL))
        return (0);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void    ft_usleep(long long time_in_ms)
{
    long long   start;
    
    start = get_time();
    while((get_time() - start) < time_in_ms)
        usleep(500);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
			i++;
		}
		else
			i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = 10 * res + (nptr[i++] - '0');
	return (res * sign);
}