#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  int my_pid = getpid();

  int result = co_yield(my_pid, 123);

  if(result == -1)
    printf("PASS: self-yield failed\n");
  else
    printf("FAIL: expected -1, got %d\n", result);

  exit(0);
}