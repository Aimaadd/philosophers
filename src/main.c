/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:03:11 by aimad             #+#    #+#             */
/*   Updated: 2024/04/08 09:34:54 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_program			program;
	t_philo				philos[MAX_PHILOS];
	pthread_mutex_t		forks[MAX_PHILOS];

	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program /*, forks*/);
	return (0);
}

// Need to create threads for each philosopher
// Need to create a thread for the monitor
// Need to create a thread for the death checker
// Need to create a thread for the meal checker
// Need to create a thread for the write checker
// Need to create a thread for the dead checker
