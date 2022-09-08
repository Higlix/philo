#include "bphilo.h"

void    semaphore_init(t_data *data)
{
    data->sem_forks = sem_open(SEM_FORK, O_CREAT, 0644, data->nop);
    data->sem_write = sem_open(SEM_WRITE, O_CREAT, 0644, 1);
    data->sem_done = sem_open(SEM_DIED, O_CREAT, 0644, 0);
    if (data->sem_forks == SEM_FAILED || data->sem_write == SEM_FAILED ||
        data->sem_done == SEM_FAILED)
        exit (1);
}

void    philo_init(t_data *data)
{
    int index;

    data->philo = malloc(sizeof(t_philo) * data->nop);
    index = -1;
    while (++index < data->nop)
    {
        data->philo[index].id = index + 1;
        data->philo[index].eat_count = 0;
        data->philo[index].last_eat = 0;
        data->philo[index].data = data;
    }
}

void    pprocess_init(t_data *data)
{
    int index;

    index = -1;
    data->pid = (int *) malloc(sizeof(int) * data->nop);
    while (++index < data->nop)
    {
        data->pid[index] = fork();
        if (data->pid[index] == 0)
        {
            start_lifecycle(&data->philo[index]);
            return ;
        }
    }
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
    new->notepme = -1;
    if (argc == 6)
        new->notepme = ft_atoi(argv[5]);
    return (new);
}