#include "types.h"
#include "pstat.h"
#include "user.h"

// OSTEP
// update Makefile to compile ps
int main(int argc, char *argv[]) {
  struct pstat p;
  if (getpinfo(&p) < 0) {
    printf(1, "ps: geetpinfo error.\n");
    exit();
  }

  for (int i = 0; i < NPROC; i++) {
    if (p.pid[i] < 1) {
      continue;
    }
    printf(1, "pid: %d  tickets: %d  ticks: %d\n", p.pid[i], p.tickets[i],
           p.ticks[i]);
  }

  exit();
}
