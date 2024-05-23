#include <stdio.h>
#include <unistd.h>
#include <semaphore.h> 

int main()
{
    int pid = fork();
    sem_t *lock;
    sem_unlink("/lock");
    lock = sem_open("/lock", O_CREAT, 0644, 1);
    while (1)
    {
        sem_wait(lock);
        printf("pid: %d\n", pid);
        sleep(1);
        sem_post(lock);
    }
}