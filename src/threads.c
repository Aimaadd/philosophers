/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:42:16 by abentaye          #+#    #+#             */
/*   Updated: 2024/04/08 08:06:34 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//pthread_create returns 0 on success and a non-zero value on error
//vitals function to check if philo is till alive or not

void *routine(void *voidarg)
{
	t_philo *philo;

	philo = (t_philo *)voidarg;
	while (vitals(philo) == 0)
		;
	// {
	// 	philo_eating(philo);
	// 	philo_sleeping(philo);
	// 	philo_thinking(philo);
	// }
	return (voidarg);
}

int thread_create(t_program *program /*, pthread_mutex_t *forks*/)
{
	int i;
	
	i = 0;
	printf("%s num of philos = %d\n", RED, program->philos[0].num_of_philos);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &routine, &program->philos[i]) != 0)
		{
			printf("Error: Could not create thread\n");
			//function to destroy all
			return (1);
		}
		printf("%s = Thread = [%lu] %d created =\n", BLUE, (unsigned long)pthread_self(), i);
		i++;
	}
	return (0);
}