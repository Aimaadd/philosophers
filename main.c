/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:03:11 by aimad             #+#    #+#             */
/*   Updated: 2024/04/04 13:55:24 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NC	"\e[0m"
#define RED	"\e[31m"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

// printf to call thread after pthread_create


void*	routine(void *arg)
{
	arg = NULL;
	printf("test\n");
	sleep(4);
	printf("sleep done\n");
	return (void *)NULL;
}

void*	routine2(void *arg)
{
	arg = NULL;
	printf("test2\n");
	sleep(3);
	printf("sleep done2\n");
	return (void *)NULL;
}

int	main(void)
{
	int			value = 203;
	pthread_t	thread1;
	pthread_t	thread2;
	
	printf("%sMain: ERROR ! Total count is %u%s\n", RED, value, NC);
	pthread_create(&thread1, NULL, routine, NULL);
	pthread_create(&thread2, NULL, routine2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (0);
}
