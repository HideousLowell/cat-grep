#include <check.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(test_s21_cat) {
  FILE *s21_cat, *cat;
  s21_cat = fopen("s21_cat.txt", "rt");
  cat = fopen("cat.txt", "rt");
  if (!s21_cat || !cat)
    exit(0);
  char a = '\0';
  char b = '\0';
  while (a != EOF && b != EOF) {
    a = getc(s21_cat);
    b = getc(cat);
    ck_assert_int_eq(a, b);
  }
  fclose(s21_cat);
  fclose(cat);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  SRunner *sr = srunner_create(s1);
  TCase *s21_catCase = tcase_create("catTest");
  suite_add_tcase(s1, s21_catCase);
  tcase_add_test(s21_catCase, test_s21_cat);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);
  srunner_free(sr);
  return 0;
}
