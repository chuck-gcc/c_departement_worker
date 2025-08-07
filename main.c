#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define department_count
#define DEP_MAX 101





void *worker_department(void *i)
{
    pid_t   thread_pid;

    thread_pid = getpid();
    printf("voici le pidss %d et le thread number %d\n", thread_pid, *(int *)i);
    return(NULL);
}

int get_french_departement(int i, int *is_corse)
{
    int departement;

    if(i == 20 && *is_corse == 0)
    {
        departement = 200;
        *is_corse = 1;
    }
    else if(i == 20 && *is_corse == 1)
    {
        departement = 201;
    }
    else
        departement = i;

    if( departement > 95 && departement != 200 && departement != 201)
    {
        departement = departement + 875;
        if(departement == 975)
            departement = 976;
    }
    return (departement);
}
int main()
{
    int     dep_count;
    int     departement;

    pthread_t dep[DEP_MAX];
    pid_t thread_pid;

    thread_pid = getpid();
    printf("voici le pid %d\n", thread_pid);

    int i;
    int is_corse;

    dep_count = DEP_MAX;
    is_corse = 0;
    i = 1;
    while (i < DEP_MAX)
    {
        
        departement = get_french_departement(i,&is_corse);
        pthread_create(&dep[i], NULL, worker_department, &departement);
        usleep(10000);
        if(departement == 200)
            continue;
        else
            i++;
    }
    i = 0;
    is_corse = 0;
    while (i < dep_count)
    {
        departement = get_french_departement(i,&is_corse);
        pthread_join(dep[i], NULL);
        usleep(10000);
        printf("thread number %d joint\n",  departement);
        if(departement == 200)
            continue;
        else
            i++;
    }
    return(0);
}