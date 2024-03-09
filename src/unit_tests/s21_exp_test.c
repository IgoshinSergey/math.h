#include "s21_math_test.h"

START_TEST(exp_test_normal_values) {
  for (double x = 0.00001; x < 100; x += 0.345023) {
    ck_assert_double_eq_tol(s21_exp(x), exp(x), 1E-6);
  }
}
END_TEST

START_TEST(exp_test_pi_value) {
  ck_assert_double_eq_tol(s21_exp(S21_PI), exp(S21_PI), 1E-6);
}
END_TEST

START_TEST(exp_test_exp_value) {
  ck_assert_double_eq_tol(s21_exp(S21_EXP), exp(S21_EXP), 1E-6);
}
END_TEST

START_TEST(exp_test_nan_value) { ck_assert_double_nan(s21_exp(S21_NAN)); }
END_TEST

START_TEST(exp_test_inf_positive_value) {
  ck_assert_double_eq(s21_exp(S21_INF_PLUS), exp(S21_INF_PLUS));
}
END_TEST

START_TEST(exp_test_inf_negative_value) {
  ck_assert_double_eq(s21_exp(S21_INF_MINUS), exp(S21_INF_MINUS));
}
END_TEST

START_TEST(exp_test_dbl_max_value) {
  ck_assert_double_eq(s21_exp(DBL_MAX), exp(DBL_MAX));
}
END_TEST

START_TEST(exp_test_dbl_max_negative_value) {
  ck_assert_double_eq_tol(s21_exp(-DBL_MAX), exp(-DBL_MAX), 1E-6);
}
END_TEST

START_TEST(exp_test_zero_value) {
  ck_assert_double_eq_tol(s21_exp(0.), exp(0.), 1E-6);
}
END_TEST

START_TEST(exp_test_nezero_value) {
  ck_assert_double_eq_tol(s21_exp(-0.), exp(-0.), 1E-6);
}
END_TEST

Suite *suite_exp(void) {
  Suite *suite = suite_create("\033[30;43m S21_EXP \033[0m");
  TCase *tcase = tcase_create("tcase_exp");
  tcase_add_test(tcase, exp_test_normal_values);
  tcase_add_test(tcase, exp_test_pi_value);
  tcase_add_test(tcase, exp_test_exp_value);
  tcase_add_test(tcase, exp_test_nan_value);
  tcase_add_test(tcase, exp_test_inf_positive_value);
  tcase_add_test(tcase, exp_test_inf_negative_value);
  tcase_add_test(tcase, exp_test_dbl_max_value);
  tcase_add_test(tcase, exp_test_dbl_max_negative_value);
  tcase_add_test(tcase, exp_test_zero_value);
  tcase_add_test(tcase, exp_test_nezero_value);
  suite_add_tcase(suite, tcase);
  return suite;
}