#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void mystop(int signo)
{
  printf("I Received Signal : %d\n", signo);
}

int main(int argc, char **argv)
{
        int i =0;
        signal(SIGUSR1, (void *)mystop);
        signal(SIGUSR2, (void *)mystop);
        printf("%d\n",getpid());
        
        while(1)
        {
                printf("%d\n", i);
                i++;
                sleep(1);
                }
        return 1;
}