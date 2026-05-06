/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:13:57 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/06 15:34:02 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    is_thinking(t_philo *philo)
{
    if (philo_died(philo))
        return ;
    print_timestamp(philo, "is thinking");
    if (philo->data->number_of_philo %2 != 0)
        ft_usleep(philo->data->time_to_eat);
}