/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:06:26 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/15 18:56:22 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_time_eat(t_philo *lst)
{
	long	time;
	time = get_time_of_day();
	//printf("slep = %ld eat = %ld ----------%ld ----------\n",lst->cont->time_sleep,lst->cont->time_die ,time - lst->last_eat);
	if (time - lst->last_eat > lst->cont->time_die)
	{
		printf("%ld ms : %d ********is died\n", get_time_of_day() - lst->n_time, lst->numbre);
		return (5);
	}
	return 0;
}

int	philosophers_util(t_philo *lst)
{
	pthread_mutex_lock(&lst->right);
	print_msg ("has taken a fork", lst);
	pthread_mutex_lock(&lst->left);
	print_msg ("has taken a fork", lst);
	if(check_time_eat(lst))
	{
		printf("------------->>>>>>>>>>\n");
		lst->cont->n = 1;
		pthread_mutex_lock(&lst->mutex_eat);
	}
	lst->last_eat = get_time_of_day();
	print_msg("is eating", lst);
	ft_usleep(lst->cont->time_eat);
	pthread_mutex_unlock(&lst->right);
	pthread_mutex_unlock(&lst->left);
	print_msg("is sleeping", lst);
	ft_usleep(lst->cont->time_sleep);
	print_msg("is thinking", lst);
	//ft_usleep(50);
	return 0;
}



void	*philosophers(void *var)
{
	t_philo	*lst;
	lst = (t_philo *) var;
	int i= 0;
	int j =  200;
	   j++;
	printf("<<<<<<<<<------- %d\n", j);

	lst->last_eat = get_time_of_day();
	lst->n_time = get_time_of_day();
	while (i < lst->nbr_eat)
	{
		if (i == lst->nbr_eat - 1)
			lst->cont->n = 1;
		philosophers_util(lst);
		i++;
	}
	return (NULL);
}
