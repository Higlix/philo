#include "bphilo.h"

void    des_sema(void)
{
    sem_unlink(SEM_FORK);
    sem_unlink(SEM_WRITE);
    sem_unlink(SEM_DIED);
}

static  void    walking_dead(t_data *data)
{
    int index;

    index = -1;
    while (++index < data->nop)
        kill(data->pid[index], SIGKILL);
}

void    desdes(t_data *data)
{
    walking_dead(data);
    des_sema();
    free(data->pid);
    free(data->philo);
    free(data);
}