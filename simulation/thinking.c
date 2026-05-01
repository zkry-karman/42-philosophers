/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:13:57 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/01 21:55:16 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    is_thinking(t_philo *philo)
{
    if (philo_died(philo))
        return ;
    print_timestamp(philo, "is thinking");
    if (philo->data->number_of_philosophers %2 != 0)
        ft_usleep(philo->data->time_to_eat);
}