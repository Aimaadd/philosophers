/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:24:20 by abentaye          #+#    #+#             */
/*   Updated: 2024/04/11 08:44:47 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define NC	"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define BLUE	"\e[34m"
# define MAGENTA	"\e[35m"
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>
# include <stdlib.h>

# define MAX_PHILOS 300

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}				t_program;

int	is_digit(char *str);
int	check_args(int argc, char **argv);
/*----UTILS----*/
int		ft_atoi(char *str);
size_t	get_current_time(void);
size_t	time_to(size_t milliseconds);
void	destroy_all(pthread_mutex_t *forks, t_program *program);

/*----INIT FUNCTIONS----*/
void	init_args(t_philo *philo, char **argv);
void	init_philos(t_philo *philo, t_program *program,
pthread_mutex_t *forks, char **argv);
void	init_forks(pthread_mutex_t *forks, int philo_num);
void	init_program(t_program *program, t_philo *philo);
int		thread_create(t_program *program, pthread_mutex_t *forks);
int		has_time(t_philo *philo);

/*----PHILO ACTIONS----*/
void	*philo_eating(t_philo *philo);
void	*philo_thinking(t_philo *philo);
void	*philo_sleeping(t_philo *philo);

#endif