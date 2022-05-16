#include "philosophers.h"
t_info check_argv_and_return_content(int ac, char **argv)
{
    t_info cont;
    struct timeval time;
    cont.num_philo = ft_atoi(argv[1]);
    if(cont.num_philo == 1)
    {
        
 		printf("%ld 1 died",get_time_of_day());
        exit(1);
    }
    cont.time_die = ft_atoi(argv[2]);
    cont.time_eat = ft_atoi(argv[3]);
    cont.time_sleep = ft_atoi(argv[4]);
    if(argv[5])
        cont.number_eat = ft_atoi(argv[5]);
    return cont;
}

t_info init_mutex_and_philo(t_info cont)
{
    int i;
    t_philo **stack;
    stack = malloc(sizeof(t_philo *));
    *stack = NULL;
    if(!stack)
        exit(0);
    t_philo *lst;
    pthread_mutex_t fork[cont.num_philo];
    pthread_t philo[cont.num_philo];
    i = 0;
    while(i < cont.num_philo)
        if(pthread_mutex_init(&fork[i++], NULL))
            print_error();
    i = 0;
	while(i < cont.num_philo)
    {
        if (i == cont.num_philo - 1)
            lst = ft_lstnew(fork[i], fork[0]);
        else
            lst = ft_lstnew(fork[i],fork[i + 1]);
        lst->philo = philo[i];
        lst->numbre = i;
        ft_lstadd_back(stack, lst);
        i++;
    }
    cont.stack = stack;
    return cont;
}