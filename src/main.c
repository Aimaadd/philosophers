/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:03:11 by aimad             #+#    #+#             */
/*   Updated: 2024/04/12 09:20:24 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error_handler(char *str, t_program *program, pthread_mutex_t *forks)
{
	printf("%s\n", str);
	destroy_all(forks, program);
	exit (1);
}

int	args_error(char *str)
{
	printf("%s\n", str);
	exit (1);
	return (1);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
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

	if (argc == 6 || !is_digit(argv[5]))
	{
		if (argv[5] < 0)
			args_error("Error: Number of times to eat must at least 1\n");
	}
	i = 0;
	while (i < 5)
	{
		if (argv[i] < 0)
			args_error("Error: Argument must be a positive number\n");
		else if (is_digit(argv[i]))
			args_error("Error: Argument must be a number\n");
		i++;
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
	check_args(argc, argv);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	return (0);
}
