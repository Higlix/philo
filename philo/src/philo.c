#include "philo.h"

void    *philo_loop_master(void *args)
{
    t_data *data;

    data = (t_data *) args;


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
        
    }
    

    return (NULL);
}