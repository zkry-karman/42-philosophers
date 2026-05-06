/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:14:54 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/06 15:37:54 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_timestamp(philo, "has taken a fork");
	while (!philo_died(philo))
		usleep(1000);
	pthread_mutex_unlock(philo->l_fork);
}
