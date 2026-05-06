/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:43:16 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/06 15:37:27 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_philo *philos, t_data *data)
{
	if (philos)
		free (philos);
	if (data)
		free (data);
}
