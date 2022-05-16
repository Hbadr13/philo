#include "philosophers.h"
typedef struct philosophers{
    int n;

    char *str;
    int time;
    int *tab;
    pthread_mutex_t mutex;
}t_philo;
void *foorr1(void *ttt)
{
    t_philo *cont;
    cont = (t_philo *)ttt;
    int i;
    pthread_mutex_lock(&cont->mutex);
    
    i = 0;
    while(i < 10000)
    {
        cont->n++;
        i++;
    }
    pthread_mutex_unlock(&cont->mutex);
    
    return NULL;
}

int main()
{
    pthread_t p1;
    pthread_t p2;
    t_philo cont;
    pthread_mutex_t mutex;
    int tabb[10] = {2, 4, 2};
    cont.tab = malloc(sizeof(int) * 10);
    cont.tab = tabb;
    cont.n = 0;

    cont.tab = tabb;
    pthread_mutex_init(&mutex,NULL);
    cont.mutex = mutex;
    pthread_create(&p1, NULL, foorr1, &cont);
    pthread_create(&p2, NULL, foorr1, &cont);

    pthread_join(p1,NULL); 
    pthread_join(p2,NULL);  
    printf("%d\n",cont.n);  
}