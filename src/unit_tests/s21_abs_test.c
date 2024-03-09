#include "s21_math_test.h"

START_TEST(abs_test_normal_values) {
  for (int x = -100; x < 100; x += 1) {
    ck_assert_int_eq(s21_abs(x), abs(x));
  }
}
END_TEST

START_TEST(abs_test_int_max) {
  ck_assert_int_eq(s21_abs(INT_MAX), abs(INT_MAX));
}
END_TEST

START_TEST(abs_test_int_min) {
  ck_assert_int_eq(s21_abs(INT_MIN), abs(INT_MIN));
}
END_TEST

Suite *suite_abs(void) {
  Suite *suite = suite_create("\033[30;43m S21_ABS \033[0m");
  TCase *tcase = tcase_create("tcase_abs");
  tcase_add_test(tcase, abs_test_normal_values);
  tcase_add_test(tcase, abs_test_int_max);
  tcase_add_test(tcase, abs_test_int_min);
  suite_add_tcase(suite, tcase);
  return suite;
}