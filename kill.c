#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char**argv)
{
    kill(43361, SIGUSR1);
    sleep(1);
    kill(43361, SIGUSR2);
}