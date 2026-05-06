/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:13:46 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/06 15:38:16 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_sleeping(t_philo *philo)
{
	if (philo_died(philo))
		return ;
	print_timestamp(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}
