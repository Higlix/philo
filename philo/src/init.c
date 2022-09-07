#include "philo.h"

void philo_init(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->nop)
    {
        data->philo[i].id = i + 1;
        data->philo[i].l_fork = i;
        data->philo[i].r_fork = (i + 1) % data->nop;
        data->philo[i].data = data;
        data->philo[i].eat_count = 0;
        data->philo[i].last_ate = 0;
        data->philo[i].thread_id = 0;     
    }
}

void mutex_init(t_data *data)
{
    int i;

    data->philo = malloc(sizeof(t_philo) * data->nop);
    data->fork = malloc(sizeof(pthread_mutex_t) * data->nop);
    i = 0;
    while (i < data->nop)
        pthread_mutex_init(&data->fork[i++], NULL);
    pthread_mutex_init(&data->buffer, NULL);
}

void thread_init(t_data *data)
{
    int i;
    pthread_t cycle_id;

    i = -1;
    while (++i < data->nop)
        pthread_create(&data->philo[i].thread_id, NULL, 
            &philo_loop, &data->philo[i]);
    pthread_create(&cycle_id, NULL, &philo_loop_master, data);
    pthread_join(cycle_id, NULL);
}

t_data *data_init(int argc, char ** argv)
{
    t_data *new;

    if (arg_validater(argc, argv))
        exit(ERROR);
    new = (t_data *) malloc(sizeof(t_data));
    new->nop = ft_atoi(argv[1]);
    new->ttd = ft_atoi(argv[2]);
    new->tte = ft_atoi(argv[3]);
    new->tts = ft_atoi(argv[4]);
    new->running = true;
    new->cycle_count = 0;
    new->notepme = -1;
    if (argc == 6)
        new->notepme = ft_atoi(argv[5]);
    return (new);
}