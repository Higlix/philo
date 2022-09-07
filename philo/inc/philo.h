#ifndef PHILO_H
# define PHILO_H

# define ERROR -1

# define pTHINKING "is thinking"
# define pEATING "is eating"
# define pSLEEPING "is sleeping"
# define pFORKING "has taken a fork"
# define pDEAD "has died"

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_state
{
    THINKING,
    EATING,
    SLEEPING,
    FORKING,
    DEAD
}   t_state;

typedef struct s_data   t_data;

typedef struct s_philo
{
    int id;
    int l_fork;
    int r_fork;
    int eat_count;
    struct s_philo *next;
    pthread_t thread_id;
    uint64_t last_ate;
    t_data  *data;
}   t_philo;

typedef struct s_data
{
    int nop;
    int ttd;
    int tte;
    int tts;
    int notepme;
    int cycle_count;
    bool running;
    t_philo *philo;
    pthread_mutex_t *fork;
    pthread_mutex_t buffer;
}   t_data;

void    do_philo(int argc, char **argv);
void    do_error(int argc);
void    philo_init(t_data *data);
void    mutex_init(t_data *data);
void    thread_init(t_data *data);
void    print_action(t_philo *philo, int key, uint64_t ms);
void    philo_do(t_philo *philo, int key, uint64_t ms);
void    p_pick_fork(t_philo *philo, uint64_t ms);
void    p_drop_fork(t_philo *philo, uint64_t ms);
void    p_eat(t_philo *philo, uint64_t ms);
void    p_sleep(t_philo *philo, uint64_t ms);
void    p_think(t_philo *philo, uint64_t ms);

void    *philo_loop(void *args);
void    *philo_loop_master(void *args);

int     arg_validater(int argc, char **argv);
int	    ft_atoi(const char *nptr);

bool    arg_checker(t_data *data);

uint64_t	get_time_ms(void);

t_data *data_init(int argc, char ** argv);



#endif