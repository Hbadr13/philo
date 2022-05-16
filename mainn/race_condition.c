#include "philosophers.h"
typedef struct philosophers{
    int n;

    char *str;
    int time;
    int *tab;
    pthread_mutex_t mutex;
}t_philo;
void *min(void *ttt)
{
    t_philo *cont;
    cont = (t_philo *)ttt;
    int min;
    int i;
    min = cont->tab[0];
    i = 0;
    while (i < 10)
    {
        if (cont->tab[i] < min)
            min = cont->tab[i];
        i++;
    }
    printf("min = %d\n", min);
    cont->n++;
    return cont;
}
void *max(void *ttt)
{
    t_philo *cont;
    cont = (t_philo *)ttt;
    int max;
    int i;
    max = cont->tab[0];
    i = 0;
    while (i < 10)
    {
        if (cont->tab[i] > max)
            max = cont->tab[i];
        i++;
    }
    printf("max = %d\n", max);
    cont->n++;
    return cont;
}
void *foorr(void *ttt)
{
    t_philo *cont;
    cont = (t_philo *)ttt;
    int i;
    while(i < 10000)
    {
        cont->n ++;
        i++;
    }
    return NULL;
}
int main()
{
    pthread_t p1;
    pthread_t p2;
    t_philo cont;
    int tabb[10] = {2, 4, 2};
    cont.tab = malloc(sizeof(int) * 10);
    cont.tab = tabb;
    cont.n = 0;

    cont.tab = tabb;

    pthread_create(&p1, NULL, foorr, &cont);
    pthread_create(&p2, NULL, foorr, &cont);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);  
    printf("%d",cont.n);  
}