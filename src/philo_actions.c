/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 07:40:24 by abentaye          #+#    #+#             */
/*   Updated: 2024/04/12 08:31:12 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	printf("%sPhilosopher %d has taken a fork\n", YELLOW, philo->id);
	if (philo->num_of_philos == 1)
	{
		printf("%sPhilosopher %d is eating\n", YELLOW, philo->id);
		time_to(philo->time_to_eat);
		pthread_mutex_unlock(philo->r_fork);
	}
	pthread_mutex_lock(philo->l_fork);
	printf("%sPhilosopher %d has taken a fork\n", YELLOW, philo->id);
	printf("%sPhilosopher %d has 2 forks and is eating\n", GREEN, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = 1;
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->eating = 0;
	time_to(philo->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

void	*philo_thinking(t_philo *philo)
{
	printf("%sPhilosopher %d is thinking\n", GREEN, philo->id);
	return (NULL);
}

void	*philo_sleeping(t_philo *philo)
{
	printf("%sPhilosopher %d is sleeping\n", RED, philo->id);
	time_to(philo->time_to_sleep);
	return (NULL);
}
