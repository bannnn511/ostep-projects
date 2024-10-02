#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    puts("wunzip: file1 [file2 ...]");
    return 1;
  }

  FILE *fp;

  for (size_t i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("wunzip: cannot open file\n");
      return -1;
    }

    int count = 0;
    while (fread(&count, 4, 1, fp)) {
      char buff[1];
      fread(buff, 1, 1, fp);
      for (int j = 0; j < count; j++) {
        printf("%c", *buff);
      }
    }

    fclose(fp);
  }

  return 0;
}
