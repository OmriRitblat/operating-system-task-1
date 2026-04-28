#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int pid1 = getpid();
    int pid2 = fork();

    if(pid2 == 0) {
        for(int i = 0; i < 5; i++){
        int value = co_yield(pid1, 1); // Yield to parent with value 42
        printf("Child received %d\n", value);
        }
    } else {
        for(int i = 0; i < 5; i++){
        // parent process
        int value = co_yield(pid2, 2); // Yield to child and wait for value
        printf("Parent received %d\n", value);
        }
    }
        return 0;
}