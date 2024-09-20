#include "types.h"
#include "pstat.h"
#include "user.h"

// Userspace Program that writes to 0x0
int main(int argc, char *argv[]) {
  // int *addr = 0x0;
  // *addr = 1234;
  // printf(1, "still here\n");

  struct pstat *p;
  p = 0;

  printf(1, "b4 syscall\n");
  if (getpinfo(p) < 0) {
    printf(2, "syscall check null\n");
  }
  printf(1, "still here\n");

  exit();
}
