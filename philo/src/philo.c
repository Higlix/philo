#include "philo.h"

void    *philo_loop_master(void *args)
{
    t_data *data;
    int index;

    data = (t_data *) args;
    index = 0;
    while (true) 
    {
        if (data->cycle_count == data->nop)
            break ;
        if (index == data->nop)
            index = 0;
        usleep(data->nop * 0.25 * 1000);
        
    }

    return (NULL);
}

void    *philo_loop(void *args)
{
    t_philo *philo;

    philo = (t_philo *) args;
    philo->last_ate = get_time_ms();
    if (philo->id % 2 == 0)
    {
        p_think(philo, get_time_ms());
        usleep(philo->data->tte * 0.25 * 1000);
    }
    while (philo->data->running)
    {
        p_pick_fork(philo, get_time_ms());
        p_eat(philo, get_time_ms());
        p_drop_fork(philo, get_time_ms());
        p_think(philo, get_time_ms());
        if (philo->eat_count == philo->data->notepme)
        {
            philo->data->cycle_count++;
            break ;
        }
        p_sleep(philo, get_time_ms());
    }
    

    return (NULL);
}