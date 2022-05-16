/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:06:05 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/14 12:23:26 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info	check_argv_and_return_content(int ac, char **argv)
{
	t_info	cont;

	cont.num_philo = ft_atoi(argv[1]);
	if (cont.num_philo == 1)
		return (ft_exit(cont, 2));
	cont.time_die = ft_atoi(argv[2]);
	cont.time_eat = ft_atoi(argv[3]);
	cont.time_sleep = ft_atoi(argv[4]);
	if(cont.time_die == -1 ||cont.time_eat == -1 || cont.time_sleep == -1)
		return(ft_exit(cont, 1));
	if (argv[5])
	{
		cont.number_eat = ft_atoi(argv[5]);
		if(cont.number_eat == -1)
			return(ft_exit(cont, 1));
	}
	else
		cont.number_eat = 0;
	return (cont);
}
