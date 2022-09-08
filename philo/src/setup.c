#include "philo.h"

void    detach_philo(t_data *data)
{
    int index;

    index = 0;
    while (index < data->nop)
        pthread_detach(data->philo[index].thread_id);
}

void    free_philo(t_data *data)
{
    int i;

    i = 0;
    detach_philo(data);
    while (i < data->nop)
    {
        pthread_mutex_destroy(&data->fork[i]);
        i++;
    }
    pthread_mutex_destroy(&data->buffer);
    free(data->philo);
    free(data->fork);
    free(data);
}

void    print_action(t_philo *philo, int key, uint64_t ms)
{
    const char *states[6] = {pTHINKING, pEATING, pSLEEPING, pFORKING, pDEAD, NULL};
    
    if (!philo->data->running)
        return ;
    pthread_mutex_lock(&philo->data->buffer);
    printf("%llu %d %s\n", ms, philo->id, states[key]);
    pthread_mutex_unlock(&philo->data->buffer);
}

uint64_t	get_time_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void    do_philo(int argc, char **argv)
{
    t_data *data;

    data = data_init(argc, argv);
    mutex_init(data);
    philo_init(data);
    thread_init(data);
    free_philo(data);
}