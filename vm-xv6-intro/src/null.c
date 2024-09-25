// #include "types.h"
// #include "pstat.h"
// #include "user.h"

// // Userspace Program that writes to 0x0
// int main(int argc, char *argv[]) {
//   char *c = 0;
//   printf(1, "%x\n", *c);
//   c++;
//   printf(1, "%x\n", *c);
//   c++;
//   printf(1, "%x\n", *c);

//   exit();
// }

#include "types.h"
#include "user.h"

int main() {
  int pid;
  int rc = mprotect((void *)4096, 4096);
  printf(1, "XV6_TEST_OUTPUT mprotect returned %d\n", rc);

  pid = fork();
  if (pid < 0) {
    printf(1, "XV6_TEST_OUTPUT init: fork failed\n");
    exit();
  }
  if (pid == 0) {
    int rc = munprotect((void *)4096, 4096);
    *(int *)4096 = 1;
    printf(1, "XV6_TEST_OUTPUT mprotect failed in child process\n");
  }
  wait();
  exit();
}
