#include <check.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(test_s21_grep) {
  FILE *s21_grep, *grep;
  s21_grep = fopen("s21_grep.txt", "rt");
  grep = fopen("grep.txt", "rt");
  if (!s21_grep || !grep)
    exit(0);
  char a = '\0';
  char b = '\0';
  while (a != EOF && b != EOF) {
    a = getc(s21_grep);
    b = getc(grep);
    ck_assert_int_eq(a, b);
  }
  fclose(s21_grep);
  fclose(grep);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  SRunner *sr = srunner_create(s1);
  TCase *s21_grepCase = tcase_create("grepTest");
  suite_add_tcase(s1, s21_grepCase);
  tcase_add_test(s21_grepCase, test_s21_grep);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);
  srunner_free(sr);
  return 0;
}
