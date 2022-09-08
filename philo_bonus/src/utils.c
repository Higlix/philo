#include <limits.h>
#include "bphilo.h"

void    print_action(t_philo *philo, int key, uint64_t ms)
{
    const char *states[6] = {pTHINKING, pEATING, pSLEEPING, pFORKING, pDEAD, NULL};
    
    sem_wait(philo->data->sem_write);
    printf("%llu %d %s\n", ms, philo->id, states[key]);
    sem_wait(philo->data->sem_write);
}

uint64_t	get_time_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

static int	ft_isspace(char chr)
{
	if ((chr >= 9 && chr <= 13) || chr == ' ')
		return (1);
	return (0);
}

static int	ft_isaret(char c, int *index)
{
	int	isaret;

	isaret = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			isaret *= -1;
		*index += 1;
	}
	return (isaret);
}

int	ft_atoi(const char *nptr)
{
	unsigned long	ret_val;
	int				index;
	int				isaret;

	index = 0;
	ret_val = 0;
	if (*nptr == '\0')
		return (0);
	while (ft_isspace(nptr[index]))
		index++;
	isaret = ft_isaret(nptr[index], &index);
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		ret_val = (ret_val * 10) + (nptr[index] - '0');
		index++;
	}
	if (ret_val > LONG_MAX)
	{
		if (isaret == -1)
			return (0);
		return (-1);
	}
	return (ret_val * isaret);
}