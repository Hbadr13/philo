/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:46 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/15 19:00:37 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define  PRINT_FORK 4
# define  PRINT_EAT 5
# define  PRINT_SLEEP 6
# define  PRINT_THINK 7

#define KRED  "\x1B[31m"
#define KYELLOW "\x1B[32m"
#define KGREEN   "\x1B[33m"
#define KBLUE  "\x1B[34m"
#define KMAGENTA  "\x1B[35m"
#define KCYAN  "\x1B[36m"
#define KWHITE  "\x1B[37m"
#define KNORMAL  "\x1B[0m"



typedef struct philosophers{
	int						num_philo;
	long					time_die;
	long					time_eat;
	long					time_sleep;
	int						number_eat;
	int						n_exit;
	struct philosopherss	**stack;
	int n;
}t_info;

typedef struct philosopherss{
	pthread_mutex_t			left;
	pthread_mutex_t			right;
	pthread_mutex_t			mutex_eat;
	pthread_mutex_t			mutex_sleep;
	pthread_mutex_t			mutex_think;
	pthread_t				philo;
	int						numbre;
	int						died;
	long					n_time; 
	long					last_eat;
	int						nbr_eat;
	struct philosophers		*cont;
	struct philosopherss	*next;
}t_philo;
  
int		main(int ac, char **argv);
void	*philosophers(void *var);
int		  ft_atoi(char *str);
t_info	check_argv_and_return_content(int ac, char **argv);
int	print_error(void);
t_philo	*ft_lstnew(pthread_mutex_t left, pthread_mutex_t right);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
t_info	init_mutex_and_philo(t_info cont);
void	print_msg(char *s, t_philo *lst);
void	ft_usleep(long ms);
long	get_time_of_day(void);
void	*ft_calloc(size_t size, size_t cont_ptr);
t_info ft_exit(t_info  cont,int index);
int	check_time_eat(t_philo *lst);

#endif
