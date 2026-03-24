/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:02:37 by karmanz           #+#    #+#             */
/*   Updated: 2026/03/24 23:07:56 by karmanz          ###   ########.fr       */
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