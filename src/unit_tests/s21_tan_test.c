#include "s21_math_test.h"

START_TEST(tan_test_normal_values) {
  for (double x = -100; x < 100; x += 1.345023) {
    ck_assert_double_eq_tol(s21_tan(x), tan(x), 1E-6);
  }
}
END_TEST

START_TEST(tan_test_pi_value) {
  ck_assert_double_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1E-6);
}
END_TEST

START_TEST(tan_test_nan_value) { ck_assert_double_nan(s21_tan(S21_NAN)); }
END_TEST

START_TEST(tan_test_inf_positive_value) {
  ck_assert_double_nan(s21_tan(S21_INF_PLUS));
}
END_TEST

START_TEST(tan_test_inf_negative_value) {
  ck_assert_double_nan(s21_tan(S21_INF_MINUS));
}
END_TEST

START_TEST(tan_test_zero_value) {
  ck_assert_double_eq_tol(s21_tan(0.), tan(0.), 1E-6);
}
END_TEST

START_TEST(tan_test_nezero_value) {
  ck_assert_double_eq_tol(s21_tan(-0.), tan(-0.), 1E-6);
}
END_TEST

Suite *suite_tan(void) {
  Suite *suite = suite_create("\033[30;43m S21_TAN \033[0m");
  TCase *tcase = tcase_create("tcase_tan");
  tcase_add_test(tcase, tan_test_normal_values);
  tcase_add_test(tcase, tan_test_pi_value);
  tcase_add_test(tcase, tan_test_nan_value);
  tcase_add_test(tcase, tan_test_inf_positive_value);
  tcase_add_test(tcase, tan_test_inf_negative_value);
  tcase_add_test(tcase, tan_test_zero_value);
  tcase_add_test(tcase, tan_test_nezero_value);
  suite_add_tcase(suite, tcase);
  return suite;
}