#include "bphilo.h"

int     ft_isnum_buff(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str [i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int     arg_validater(int argc, char **argv)
{
    int count;

    count = 1;
    while (count < argc)
    {
        if (ft_isnum_buff(argv[count]))
            return (1);
        count++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_data  *data;

    data = data_init(argc, argv);
    semaphore_init(data);
    philo_init(data);
    pprocess_init(data);
    pthread_create(&data->checker, NULL, checker_function, &data);
    pthread_detach(data->checker);
    sem_wait(data->sem_done);
    return (0);
}