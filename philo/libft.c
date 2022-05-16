#include"philosophers.h"

void	print_error(void)
{
	write(2, "error", 5);
	exit(0);
}

static	void	ft_atoi_help(char *str, int *i, int *nb)
{
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
			print_error();
		*nb = *nb * 10 + str[*i] - '0';
		(*i)++;
	}
}

int	ft_atoi(char	*str)
{
	int		sing;
	int		i;
	int		nb;

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
		print_error();
	ft_atoi_help(str, &i, &nb);
	if ((nb * sing) < 1 || (nb * sing) > 2147483647)
		print_error();
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
	while(new_fin)
	{
		if(!new_fin->next)
			break;
		new_fin = new_fin->next;
	}
	new_fin->next = new;
}

t_philo	*ft_lstnew(pthread_mutex_t right ,pthread_mutex_t left)
{
	t_philo	*n_node;

	n_node = (t_philo *)malloc(sizeof(t_philo));
	if (!n_node)
		exit (0);
	n_node->right = right;
	n_node->left = left;
	n_node->next = NULL;
	return (n_node);
}