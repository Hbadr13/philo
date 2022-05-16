/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:06:01 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/15 19:00:17 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **argv)
{
	t_philo	*lst;
	t_info	cont;
	t_philo	*node;
	int		i;
	if (ac != 5 && ac != 6)
		return (printf("%serror\n",KRED) && 0);
	i = 0;
	cont.n = 0;
	cont.n_exit = 1;
	cont = check_argv_and_return_content(ac, argv);
	if(cont.n_exit == -1)
		return (3);
	cont = init_mutex_and_philo(cont);
	if(cont.n_exit == -1)
		return (4); 
	i = 0;
	lst = *(cont.stack);
	printf("%d\n",lst->nbr_eat);
 	while (lst)
	{
		lst->cont = &cont;
		if (pthread_create(&lst->philo, NULL, philosophers, lst))
			return (0);
		lst = lst->next;
	}
	node = *cont.stack;
	// while (node)
	// {
	// 	if(pthread_join(node->philo, NULL))
	// 		return (0);
	// 	node = node->next;
	// }
	
	while(1)
	{
		if(cont.n == 1)
			return (0);
	}
	
	// node = *(cont.stack);

	
	return (5);
}
