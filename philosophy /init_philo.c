/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:05:59 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/15 12:50:08 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info	init_mutex_print(t_info cont)
{
	int				i;
	t_philo			*lst;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_slepp;
	pthread_mutex_t	m_think;
	pthread_t		*philoo;

	philoo = malloc(sizeof(pthread_t) * cont.num_philo);
	if (!philoo)
		return(ft_exit(cont, 0));
	i = 0;
	if(pthread_mutex_init(&m_eat, NULL))
		return (ft_exit(cont, 3));
	if(pthread_mutex_init(&m_slepp, NULL))
		return (ft_exit(cont, 3));
	if(pthread_mutex_init(&m_think, NULL))
		return (ft_exit(cont, 3));
	lst = *(cont.stack);
	while (lst)
	{
		lst->mutex_eat = m_eat;
		lst->mutex_sleep = m_slepp;
		lst->mutex_think = m_think;
		lst->philo = philoo[i];
		lst->numbre = i;
		lst = lst->next;
		i++;
	}
	return (cont);
}

t_info	init_mutex_and_philo(t_info cont)
{
	int				i;
	t_philo			**stack;
	t_philo			*lst;
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t) * cont.num_philo);
	stack = malloc(sizeof(t_philo *));
	if (!stack || !fork)
		return (ft_exit(cont, 0));
	*stack = NULL;
	i = 0;
	while (i < cont.num_philo)
	{
		if (pthread_mutex_init(&fork[i], NULL))
			return(ft_exit(cont,3));
		i++;
	}
	i = 0;
	while (i < cont.num_philo)
	{
		if (i == cont.num_philo - 1)
			lst = ft_lstnew(fork[i], fork[0]);
		else
			lst = ft_lstnew(fork[i], fork[i + 1]);
		if (!lst)
			return (ft_exit(cont, 0));
		ft_lstadd_back(stack, lst);
		i++;
	}
	cont.stack = stack;
	return (init_mutex_print(cont));
}
