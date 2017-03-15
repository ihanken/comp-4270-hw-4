#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_FORKS 2

int main(int argc, char *argv[]) {
    long pid = -1;

    if ((pid = fork()) != 0) printf("Hello world! It's me, process #%ld\n", pid);

    sleep(2);

    if ((pid = fork()) != 0) printf("Hello world! It's me again, process #%ld\n", pid);
}
