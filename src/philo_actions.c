/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 07:40:24 by abentaye          #+#    #+#             */
/*   Updated: 2024/04/08 08:04:13 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    *eating_philo(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    printf("%sPhilosopher %d has taken a fork\n", YELLOW, philo->id);
    return (NULL);
}