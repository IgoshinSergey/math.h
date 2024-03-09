#include "s21_math_test.h"

START_TEST(log_test_positive_values) {
  for (double x = 0.000001; x < 100; x += 0.345023) {
    ck_assert_double_eq_tol(s21_log(x), log(x), 1E-6);
  }
}
END_TEST

START_TEST(log_test_negative_values) {
  for (double x = -100; x < 0; x += 0.345023) {
    ck_assert_double_nan(s21_log(x));
  }
}
END_TEST

START_TEST(log_test_exp_value) {
  ck_assert_double_eq_tol(s21_log(S21_EXP), log(S21_EXP), 1E-6);
}
END_TEST

START_TEST(log_test_nan_value) { ck_assert_double_nan(s21_log(S21_NAN)); }
END_TEST

START_TEST(log_test_inf_positive_value) {
  ck_assert_double_eq(s21_log(S21_INF_PLUS), log(S21_INF_PLUS));
}
END_TEST

START_TEST(log_test_inf_negative_value) {
  ck_assert_double_nan(s21_log(S21_INF_MINUS));
}
END_TEST

START_TEST(log_test_dbl_max_value) {
  ck_assert_double_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1E-6);
}
END_TEST

START_TEST(log_test_dbl_max_negative_value) {
  ck_assert_double_nan(s21_log(-DBL_MAX));
}
END_TEST

START_TEST(log_test_zero_value) { ck_assert_double_eq(s21_log(0.), log(0.)); }
END_TEST

START_TEST(log_test_nezero_value) {
  ck_assert_double_eq(s21_log(-0.), log(-0.));
}
END_TEST

Suite *suite_log(void) {
  Suite *suite = suite_create("\033[30;43m S21_LOG \033[0m");
  TCase *tcase = tcase_create("tcase_log");
  tcase_add_test(tcase, log_test_positive_values);
  tcase_add_test(tcase, log_test_negative_values);
  tcase_add_test(tcase, log_test_exp_value);
  tcase_add_test(tcase, log_test_nan_value);
  tcase_add_test(tcase, log_test_inf_positive_value);
  tcase_add_test(tcase, log_test_inf_negative_value);
  tcase_add_test(tcase, log_test_dbl_max_value);
  tcase_add_test(tcase, log_test_dbl_max_negative_value);
  tcase_add_test(tcase, log_test_zero_value);
  tcase_add_test(tcase, log_test_nezero_value);
  suite_add_tcase(suite, tcase);
  return suite;
}