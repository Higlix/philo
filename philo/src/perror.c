#include "philo.h"

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

void    do_error(int argc)
{
    if (argc <= 3)
    {
        write(1, "USAGE_ERROR: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]\n", 128);
        write(1, "[number_of_times_each_phiosopher_must_eat] this arg is optional\n", 64);
    }
}