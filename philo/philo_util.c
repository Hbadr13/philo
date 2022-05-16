/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:42 by hbadr             #+#    #+#             */
/*   Updated: 2022/04/20 14:35:42 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
long  get_time_of_day()
{
	struct timeval te;
	gettimeofday(&te, NULL);
	long  milliseconds =  te.tv_sec * 1000 + te.tv_usec / 1000;
	return milliseconds;
}