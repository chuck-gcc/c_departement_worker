#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define department_count

void *worker_department(void *i)
{
    pid_t thread_pid;

    thread_pid = getpid();
    printf("voici le pidss %d et le thread number %d\n", thread_pid, *(int *)i);
    return(NULL);
}


int main()
{
    int dep_count;
    pthread_t dep[74];
    pid_t thread_pid;

    thread_pid = getpid();
    printf("voici le pid %d\n", thread_pid);

    int i;

    dep_count = 74;
    i = 1;
    while (i < dep_count)
    {
        pthread_create(&dep[i], NULL, worker_department, &i);
        usleep(100);
        i++;
    }
    i = 0;
    while (i < dep_count)
    {
        pthread_join(dep[i], NULL);
        printf("thread number %d joint\n",  i);
        i++;
    }
    return(0);
}