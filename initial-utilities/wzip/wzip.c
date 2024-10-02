#include <stdio.h>
#include <string.h>

void write_file(int count, char *buf) {
  fwrite(&count, 4, 1, stdout);
  fwrite(buf, 1, 1, stdout);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("wzip: file1 [file2 ...]");
    return 1;
  }

  FILE *fp;
  int count = 0;
  char buff[1] = {0}, old_buff[1] = {0};

  for (size_t i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("wzip: cannot open file\n");
      return -1;
    }

    while (fread(buff, 1, 1, fp)) {
      if (strncmp(buff, old_buff, 1) == 0) {
        count++;
      } else {
        if (old_buff[0] != '\0') {
          write_file(count,old_buff );
        }
        count = 1;
        strncpy(old_buff, buff, sizeof(old_buff));
      }
    }

    fclose(fp);
  }

  write_file(count, old_buff);

  return 0;
}
