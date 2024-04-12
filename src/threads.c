/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:42:16 by abentaye          #+#    #+#             */
/*   Updated: 2024/04/12 09:34:36 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

//pthread_create returns 0 on success and a non-zero value on error
//vitals function to check if philo is till alive or not

void	*routine(void *voidarg)
{
	t_philo	*philo;

	philo = (t_philo *)voidarg;
	while (has_time(philo) == 0)
	{
		if (has_time(philo) == 1)
		{
			printf("%sPhilosopher %d died\n", RED, philo->id);
			break ;
			return (voidarg);
		}
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (voidarg);
}

int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	doctor;
	int			i;

	i = 0;
	if (pthread_create(&doctor, NULL, monitor, program) != 0)
		error_handler("Could not create thread\n", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread,
				NULL, &routine, &program->philos[i]) != 0)
			error_handler("Could not create thread\n", program, forks);
		i++;
	}
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
