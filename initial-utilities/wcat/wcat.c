//
// Created by ban on 20/4/24.
//
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    FILE *fd = fopen(argv[i], "r");
    if (fd == NULL) {
      printf("wcat: cannot open file\n");
      return (1);
    }

    int line_max = LINE_MAX;
    char *ch = malloc(line_max + 1);
    if (ch == NULL) {
      printf("out of space");
      return 1;
    }

    for (;;) {
      if (fgets(ch, line_max + 1, fd) == NULL) {
        break;
      }
      printf("%s", ch);
    }
    free(ch);
  }

  return 0;
}
