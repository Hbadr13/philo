/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:42 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/15 12:39:12 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long ms)
{
	long	end;

	end = get_time_of_day() + ms;
	while (get_time_of_day() < end)
		usleep(ms / 1000);
}

void	print_msg(char *s, t_philo *lst)
{
	pthread_mutex_lock(&lst->mutex_eat);
	printf("%ld ms : %d  %s\n", get_time_of_day() - lst->n_time, lst->numbre, s);
	pthread_mutex_unlock(&lst->mutex_eat);
}



long	get_time_of_day(void)
{
	struct timeval	time;
	long			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milliseconds);
}

t_info ft_exit(t_info  cont,int index)
{
	
	 if (index == 0)
		printf("%serror   : malloc ...",KRED);
	else if(index == 1)
		printf("%serror ... : arguments\n",KRED);
	else if(index == 2)
		printf("%ld 0 died", get_time_of_day());
	else if (index == 3)
		printf("%serror   : mutex ...",KRED);
	cont.n_exit = -1;
	return cont;
}
