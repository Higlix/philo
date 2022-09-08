#ifndef BPHILO_H
# define BPHILO_H

# define ERROR -1

# define pTHINKING "is thinking"
# define pEATING "is eating"
# define pSLEEPING "is sleeping"
# define pFORKING "has taken a fork"
# define pDEAD "has died"

# define SEM_FORK   "/sem_forks"
# define SEM_WRITE  "/sem_write"
# define SEM_DIED   "/sem_died"
# define SEM_FINISH "/sem_finish"

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <inttypes.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
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
    int eat_count;
    uint64_t last_eat;
    t_data  *data;
}   t_philo;

typedef struct s_data
{
    int nop;
    int ttd;
    int tte;
    int tts;
    int notepme;
    int *pid;
    t_philo *philo;
    pthread_t   checker;

    sem_t       *sem_forks;
    sem_t       *sem_write;
    sem_t       *sem_done;
}   t_data;

t_data      *data_init(int argc, char ** argv);

uint64_t	get_time_ms(void);

void        print_action(t_philo *philo, int key, uint64_t ms);
void        semaphore_init(t_data *data);
void        philo_init(t_data *data);
void        pprocess_init(t_data *data);
void        philo_think(t_philo *philo);
void        philo_sleep(t_philo *philo);
void        philo_eat(t_philo *philo, uint64_t ms);
void        leave_fork(t_philo *philo);
void        take_fork(t_philo *philo);
void        start_lifecycle(t_philo *philo);

void        *checker_function(void  *args);

int	        ft_atoi(const char *nptr);
int         arg_validater(int argc, char **argv);

#endif