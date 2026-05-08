/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:43:16 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/08 14:27:19 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_philo *philos, t_data *data)
{
	if (philos)
		free (philos);
	if (data->forks)
		free (data->forks);
	if (data)
		free (data);
}
