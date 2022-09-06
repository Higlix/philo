#include "philo.h"

int main(int argc, char **argv)
{
    if (argc > 3)
        do_philo(argc, argv);
    else
        do_error(argc);
    return (0);
}