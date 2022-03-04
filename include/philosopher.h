/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiacomi <egiacomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:27:49 by egiacomi          #+#    #+#             */
/*   Updated: 2022/03/04 22:15:57 by egiacomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define RED "\033[1;31m"
# define RED_BLINK "\033[1;5;31m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;36m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"
# define RESET "\033[0m"

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	pthread_t		*thrd;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mtx_write;
	pthread_mutex_t	mtx_meal;
	pthread_mutex_t	mtx_death;
	struct s_philo	*philo;
	long int		start;
	int				end;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				num_eat;
	long int		last_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*ctxt;
}	t_philo;

int			main(int ac, char **av);
/* MANAGER */
// timer
long int	get_time(void);
// writer
void		writer(char *emoji, char *txt, t_philo *philo, t_data *context);
// utiliser
int			ft_atoi(const char *nptr);
int			ft_isnumber(char *nbr);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_strlen(char *str);

/* STARTER_CLOSER */
// finisher
void		usage(void);
void		finish_diner(t_data *context);
int			the_end(t_data *context);

// initializer
int			init_context(int ac, char **av, t_data *context);
int			init_mutex(t_data *context);
int			init_philo(t_data *context);
int			init_thread(t_data *context);
// parser
void		printf_error(char *str);
int			parse_error(int ac, char **av);
int			parse_context(int ac, char **av, t_data *context);

/* USER */
// checker
int			check_ok(t_philo *philo);
int			check_death(t_data *context);
int			check_eat(t_data *context);
int			check_end(t_data *context);
// eater
void		lock_forks_right_hand(t_philo *philo);
void		lock_forks_left_hand(t_philo *philo);
void		unlock_forks_right_hand(t_philo *philo);
void		unlock_forks_left_hand(t_philo *philo);
void		mtx_eat_timer(t_philo *philo);
void		mtx_num_eat(t_philo *philo);
int			eating(t_philo *philo);
// routiniser
void		*routine(void *philo);
int			thinking(t_philo *philo);
int			sleeping(t_philo *philo);

#endif