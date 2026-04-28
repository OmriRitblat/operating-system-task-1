#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    uint size = memsize();
    printf("Memory size: %d bytes\n", size);
    char *buf = malloc(20000); // Allocate some memory to test memsize after allocation
    size = memsize();
    printf("Memory size after allocation: %d bytes\n", size);
    free(buf); // Free the allocated memory
    size = memsize();
    printf("Memory size after freeing: %d bytes\n", size);
  exit(0);
}
