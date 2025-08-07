#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define department_count
#define DEP_MAX 101


void *worker_department(void *i)
{
    pid_t   thread_pid;

    thread_pid = getpid();
    printf("voici le pids %d et le thread number %d\n", thread_pid, *(int *)i);
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
#include <stdlib.h>

int main() {

    
    int status = system("cd ../oee && npm run dev");

    if (status == -1) {
        perror("system");
        return 1;
    }
    else
    {
        printf("\nvoici le status %d\n", status);

    }
    //status = system("cd ../oee && make clean");
    // if (status == -1) {
    //     perror("system");
    //     return 1;
    // }
    return 0;
}
