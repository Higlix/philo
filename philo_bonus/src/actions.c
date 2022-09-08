#include "bphilo.h"

void    take_fork(t_philo *philo)
{
    sem_wait(philo->data->sem_forks);
    print_action(philo, FORKING, get_time_ms());
    sem_wait(philo->data->sem_forks);
    print_action(philo, FORKING, get_time_ms());
}

void    leave_fork(t_philo *philo)
{
    sem_post(philo->data->sem_forks);
    sem_post(philo->data->sem_forks);
}

void    philo_eat(t_philo *philo, uint64_t ms)
{
    print_action(philo, EATING, ms);
    philo->eat_count++;
    philo->last_eat = ms;
    usleep(philo->data->tte * 1000);
}

void    philo_sleep(t_philo *philo)
{
    print_action(philo, SLEEPING, get_time_ms());
    usleep(philo->data->tts * 1000);
}

void    philo_think(t_philo *philo)
{
    print_action(philo, THINKING, get_time_ms());
}
