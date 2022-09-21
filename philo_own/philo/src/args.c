#include "philo.h"

void    set_up_args(int argc, char **argv, t_data *data)
{
    data->should_eat = -1;
    data->n_philos = ft_atoi(argv[1]);
    data->tt_die = ft_atoi(argv[2]);
    data->tt_eat = ft_atoi(argv[3]);
    data->tt_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->should_eat = ft_atoi(argv[5]);
    if (data->tt_die < 60 || data->tt_eat < 60 || data->tt_sleep < 60)
        philo_error("\"TT_DIE < 60 OR TT_EAT < 60 OR TT_SLEEP < 60\" ARGS_TOO_SMALL", ARGS_ERROR);
    else if (data->n_philos > 200)
        philo_error("\"NUMBER OF PHILOSOPHERS ARE BIGGER THAN(>) 200\" ARG_TOO_BIG", ARGS_ERROR);
    data->action = 0;
    data->running = true;
}

int    check_args(int argc, char **argv)
{
    int x;
    int y;

    if (!(argc == 6 || argc == 5))
        return (-1);
    y = 1;
    while (y < argc)
    {
        x = 0;
        while (argv[y][x])
        {
            if (!(argv[y][x] >= '0' && argv[y][x] <= '9'))
                return (-1);
            x++;
        }
        y++;
    }
    return (1);
}