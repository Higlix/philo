#include "bphilo.h"

void    *checker_function(void  *args)
{
    int index;
    t_data *data;

    data = (t_data *) args;
    index = -1;
    while (++index < data->nop)
        waitpid(-1, NULL, 0);
    sem_post(data->sem_done);
    return (NULL);
}

void    *life_cycle_checker(void *args)
{
    uint64_t    ms;
    t_philo     *philo;
    t_data      *data;

    philo = (t_philo *) args;
    data = philo->data;
    while (true)
    {
        if (philo->eat_count == data->notepme)
            break ;
        ms = get_time_ms();
        if ((int)(ms - philo->last_eat) > data->ttd)
        {
            print_action(philo, DEAD, get_time_ms());
            sem_post(data->sem_done);
            break ;
        }
        usleep(1000);
    }
    return (NULL);
}

void    start_lifecycle(t_philo *philo)
{
    pthread_t   checker_id;

    if (philo->id % 2 == 0)
    {
        philo_think(philo);
        usleep(1000);
    }
    philo->last_eat = get_time_ms();
    pthread_create(&checker_id, NULL, &life_cycle_checker, philo);
    pthread_detach(checker_id);
    while (true)
    {
        take_fork(philo);
        philo_eat(philo, get_time_ms());
        leave_fork(philo);
        philo_think(philo);
        if (philo->eat_count == philo->data->notepme)
            exit(0);
        philo_sleep(philo);
    }
    exit(0);
}