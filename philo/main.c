#include "philosophers.h"

void	ft_usleep(long ms)
{
	long	end;

	end = get_time_of_day() + ms;
	while (get_time_of_day() < end)
		usleep(ms / 1000);
}

void *myfonc(void *var)
{
    t_philo *lst;
     t_philo *node;
    lst = (t_philo *) var;
    long time;
    while(1 )
    {
        pthread_mutex_lock(&lst->mlx);
       // sleep(1);
        printf("%ld %d is thinking\n",get_time_of_day(),lst->numbre);
        pthread_mutex_lock(&lst->right);
        printf("%ld %d has taken a fork\n",get_time_of_day(),lst->numbre);
        pthread_mutex_lock(&lst->left);
        time = get_time_of_day();

        if(time - lst->last_eat > lst->cont->time_eat)
        {
             printf("%ld %d ***************************is died\n",get_time_of_day(),lst->numbre);
            node = *(lst->cont->stack);
            
              break;
            //return 0;
        }
        printf("%ld %d has taken a fork\n",get_time_of_day(),lst->numbre);
        printf("%ld %d is eating\n",get_time_of_day(),lst->numbre);
       // exit(5);
        usleep(lst->cont->time_eat*1000);
        pthread_mutex_unlock(&lst->right);
        pthread_mutex_unlock(&lst->left);
        lst->last_eat = get_time_of_day();
        
        printf("%ld %d is sleeping 😴💤\n",get_time_of_day(),lst->numbre);
        usleep(lst->cont->time_sleep *1000);
        pthread_mutex_unlock(&lst->mlx);
        
    }
    return 0;
}

int main(int ac, char **argv)
{

    if(ac != 5 && ac != 6)
        print_error();
    t_philo *lst;
    t_info cont;
    t_philo *node;
    pthread_mutex_t mlx;
    pthread_t	philo;
    pthread_mutex_init(&mlx,NULL);
    int i = 0;
    cont = check_argv_and_return_content(ac, argv);
    cont = init_mutex_and_philo(cont);
	i = 0;
    lst = *(cont.stack);
    while(lst)
    {
        lst->cont = &cont;
        lst->mlx = mlx;
        //lst->died = 5;
        pthread_create(&philo, NULL, myfonc, lst);
        pthread_detach(philo);
        ft_usleep(500);
        lst = lst->next;
    }
     node = *(cont.stack);
    while(node)
    {
        
        
        
         pthread_join(node->philo, NULL);
        //printf("%d--------------------\n",lst->died);
        // if(lst->died == 5)
        //     exit(7);
        node = node->next;
    }
    return 0;

}
