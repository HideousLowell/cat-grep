#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
};

void cat(struct flags F, char **argv) {
  FILE *fp = NULL;
  char cur = '\0';
  int error = 0;
  if ((fp = fopen(*argv, "r")) == NULL) {
    fprintf(stderr, "cat: %s: No such file or directory\n", *argv);
    error = 1;
  } else if ((cur = getc(fp)) == EOF) {
    error = 1;
  }
  if (!error) {
    int count = 1;
    if (F.n) printf("%6d\t", count++);
    if (F.b && cur != '\n') printf("%6d\t", count++);
    int first_empty_line = 0;
    char prev = '\0';
    do {
      if (first_empty_line && cur != '\n') first_empty_line = 0;
      if (first_empty_line && cur == '\n') {
        prev = cur;
        continue;
      }
      if (F.s && prev == '\n' && cur == '\n') {
        prev = cur;
        first_empty_line = 1;
        if (count == 1 + F.n) continue;
      }
      if (prev == '\n') {
        if (F.n)
          printf("%6d\t", count++);
        else if (F.b && cur != '\n')
          printf("%6d\t", count++);
      }
      if (F.e && cur == '\n') putchar('$');
      if (F.v && cur >= 0 && cur < 32 && cur != '\n' && cur != '\t')
        printf("^%c", 64 + cur);
      else if (F.t && cur == '\t')
        printf("^I");
      else
        putchar(cur);
      prev = cur;
    } while ((cur = getc(fp)) != EOF);
  }
  fclose(fp);
}

int valid_flag(struct flags *F, char c) {
  int result = 1;
  if (c == 'b')
    F->b = 1;
  else if (c == 'e')
    F->e = 1, F->v = 1;
  else if (c == 'E')
    F->e = 1;
  else if (c == 'n')
    F->n = 1;
  else if (c == 's')
    F->s = 1;
  else if (c == 't')
    F->t = 1, F->v = 1;
  else if (c == 'T')
    F->t = 1;
  else if (c == 'v')
    F->v = 1;
  else
    result = 0;
  if (F->b) F->n = 0;
  if (!result)
    fprintf(stderr,
            "cat: illegal option -- %c\nusage: cat [-benstuv] [file ...]\n", c);
  return result;
}

int s21_getopt(struct flags *F, int argc, char **argv) {
  int result = 1;
  for (int i = 1; i < argc - 1 && result; i++) {
    if (!strcmp(argv[i], "--number-nonblank")) {
      F->b = 1;
    } else if (!strcmp(argv[i], "--number")) {
      F->n = 1;
    } else if (!strcmp(argv[i], "--squeeze_blank")) {
      F->s = 1;
    } else if (argv[i][0] == '-') {
      for (size_t j = 1; j < strlen(argv[i]) && result; j++)
        result = valid_flag(F, argv[i][j]);
    }
  }
  return result;
}

int main(int argc, char **argv) {
  if (argc < 2) return 0;
  struct flags F = {0};
  if (s21_getopt(&F, argc, argv)) {
    do {
      argv++;
      argc--;
    } while (**argv == '-' && argc > 1);
    while (argc--) cat(F, argv++);
  }
  return 0;
}
