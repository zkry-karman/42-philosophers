/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:27:57 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/06 15:45:55 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threading(t_philo *philos, t_data *data)
{
	pthread_t	death_check;
	int			i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_create(&philos[i].thread, NULL, &philosopher_routine, &philos[i]);
		i++;
	}
	pthread_create(&death_check, NULL, &check_for_deaths, philos);
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(death_check, NULL);
}
