/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:03:11 by aimad             #+#    #+#             */
/*   Updated: 2024/04/11 09:38:44 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(&str[i]) < '0' || ft_atoi(&str[i]) > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6 || !is_digit(argv[5]))
	{
		if (argv[5] < 0)
		{
			printf("%sError: Argument must be greater than 0\n", RED);
			return (1);
		}
	}
	while (i < 5)
	{
		if (argv[i] < 0)
		{
			printf("%sError: Argument must be greater than 0\n", RED);
			return (1);
		}
		else if (!is_digit(argv[i]))
		{
			printf("%sError: Argument must be a number\n", RED);
			return (1);
		}
	}
	return (0);
}

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
	// check_args(argc, argv);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	return (0);
}
