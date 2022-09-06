#include "philo.h"

void    p_pick_fork(t_philo *philo, uint64_t ms)
{
    pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
    print_action(philo, FORKING, ms);
    pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
    print_action(philo, FORKING, ms);
}

void    p_drop_fork(t_philo *philo, uint64_t ms)
{
    pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
    pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
}

void    p_eat(t_philo *philo, uint64_t ms)
{
    print_action(philo, EATING, ms);
    philo->eat_count++;
    philo->last_ate = ms;
    usleep(philo->data->tte * 1000);
}

void    p_sleep(t_philo *philo, uint64_t ms)
{
    print_action(philo, SLEEPING, ms);
    usleep(philo->data->tts * 1000);
}

void    p_think(t_philo *philo, uint64_t ms)
{
    print_action(philo, THINKING, ms);
}