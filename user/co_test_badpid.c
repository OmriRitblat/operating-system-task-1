#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  int bad_pid = 99999;

  int result = co_yield(bad_pid, 123);

  if(result == -1)
    printf("PASS: yield to non-existent PID failed\n");
  else
    printf("FAIL: expected -1, got %d\n", result);

  exit(0);
}