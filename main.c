/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:03:11 by aimad             #+#    #+#             */
/*   Updated: 2024/03/31 09:15:48 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>

void* routine(void)
{
	printf("test\n");
	sleep(3);
	printf("sleep done\n");
}

int	main(void)
{
	int		value;
	pthread_t	thread1;
	pthread_t	thread2;
	
	pthread_create(&thread1, NULL, &routine, NULL);
	pthread_create(&thread2, NULL, &routine, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
