#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  int child_pid = fork();

  if(child_pid < 0){
    printf("fork failed\n");
    exit(1);
  }

  if(child_pid == 0){
    for(;;){
      sleep(10);
    }
  }

  kill(child_pid);
  sleep(10);

  int result = co_yield(child_pid, 123);

  if(result == -1)
    printf("PASS: yield to killed process failed\n");
  else
    printf("FAIL: expected -1, got %d\n", result);

  wait(0);
  exit(0);
}