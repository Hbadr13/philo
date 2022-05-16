/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:46 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/22 11:14:59 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H 
#define PHILOSOPHERS_H

#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
typedef struct philosophers{
    int num_philo;
    int time_die;
    int time_eat;
    int time_sleep;
    int number_eat;
    struct philosopherss **stack;
    pthread_mutex_t mutex;
}t_info;

typedef struct philosopherss{
    pthread_mutex_t left;
    pthread_mutex_t right;
    pthread_mutex_t mlx;
    pthread_t philo;
    int numbre;
    int died;
    long last_eat;
    
    struct philosophers *cont;
    struct philosopherss *next;
}t_philo;

int     main(int ac, char **argv);
int	    ft_atoi(char	*str);
t_info  check_argv_and_return_content(int ac, char **argv);
void	print_error(void);
t_philo	*ft_lstnew(pthread_mutex_t left ,pthread_mutex_t right);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
t_info init_mutex_and_philo(t_info cont);
long  get_time_of_day();
#endif
