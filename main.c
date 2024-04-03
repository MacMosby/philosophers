#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*routine()
{
	printf("test new again\n");
	sleep(3);
	printf("new line\n");
	return (NULL);
}

int	main()
{
	pthread_t	t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0) // last argument here is what is passed into the routine function
	{
		return (1);
	}
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	{
		return (2);
	}
	if (pthread_join(t1, NULL) != 0) // second argument is a pointer that takes the return from the thread
	{
		return (3);
	}
	if (pthread_join(t2, NULL) != 0)
	{
		return (4);
	}
	return (0);
}
