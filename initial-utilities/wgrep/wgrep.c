#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_space(char *string);

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    puts("wgrep: searchterm [file ...]");
    return 1;
  }

  FILE *fd = NULL;
  if (argc >= 3 && ((fd = fopen(argv[2], "r")) == NULL)) {
    printf("wgrep: cannot open file\n");
    return 1;
  }
  if (argc == 2) {
    fd = stdin;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&line, &len, fd)) > 0) {
    if (strstr(line, argv[1])) {
      printf("%s", line);
    }
  }

  free(line);
  fclose(fd);

  return 0;
}

char *remove_space(char *str) {
  while (isspace((unsigned char)*str))
    str++;

  if (*str == 0) // All spaces?
    return str;

  char *end;
  end = str + strlen(str) - 1;
  while (isspace((unsigned char)*end) && end > str)
    end--;

  end[1] = '\0';

  return str;
}
