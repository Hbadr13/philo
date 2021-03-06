/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:06:10 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/14 14:02:05 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	print_error(void)
{
	write(2, "error", 5);
	return (-1);
}

static	int	ft_atoi_help(char *str, int *i, int *nb)
{
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
			return (-1);
		*nb = *nb * 10 + str[*i] - '0';
		(*i)++;
	}
	return (1);
}

int	ft_atoi(char	*str)
{
	int		sing;
	int		i;
	int		nb;
	int 	ext;

	ext = 0;
	nb = 0;
	sing = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = sing * -1;
		i++;
	}
	if (!str[i])
		return (-1);
	ext = ft_atoi_help(str, &i, &nb);
	if ((nb * sing) < 1 || (nb * sing) > 2147483647 || ext == -1)
		return(-1);
	return (nb * sing);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*new_fin;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	new_fin = *alst;
	while (new_fin)
	{
		if (!new_fin->next)
			break ;
		new_fin = new_fin->next;
	}
	new_fin->next = new;
}

t_philo	*ft_lstnew(pthread_mutex_t right, pthread_mutex_t left)
{
	t_philo	*n_node;

	n_node = (t_philo *)malloc(sizeof(t_philo));
	if (!n_node)
		return (NULL);
	n_node->right = right;
	n_node->left = left;
	n_node->next = NULL;
	return (n_node);
}

void	*ft_calloc(size_t size, size_t cont_ptr)
{
	size_t	i;
	void	*ptr;

	ptr = malloc(size * cont_ptr);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(char *)ptr = '\0';
		i++;
		ptr++;
	}
	return (ptr);
}
