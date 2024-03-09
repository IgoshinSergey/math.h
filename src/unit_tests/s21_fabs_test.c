#include "s21_math_test.h"

START_TEST(fabs_test_normal_values) {
  for (double x = -100.; x < 100.; x += 0.345023) {
    ck_assert_double_eq_tol(s21_fabs(x), fabs(x), 1E-6);
  }
}
END_TEST

START_TEST(fabs_test_pi_value) {
  ck_assert_double_eq_tol(s21_fabs(S21_PI), fabs(S21_PI), 1E-6);
}
END_TEST

START_TEST(fabs_test_nan_value) { ck_assert_double_nan(s21_fabs(S21_NAN)); }
END_TEST

START_TEST(fabs_test_inf_positive_value) {
  ck_assert_double_eq(s21_fabs(S21_INF_PLUS), fabs(S21_INF_PLUS));
}
END_TEST

START_TEST(fabs_test_inf_negative_value) {
  ck_assert_double_eq(s21_fabs(S21_INF_PLUS), fabs(S21_INF_PLUS));
}
END_TEST

START_TEST(fabs_test_dbl_max_value) {
  ck_assert_double_eq_tol(s21_fabs(DBL_MAX), fabs(DBL_MAX), 1E-6);
}
END_TEST

START_TEST(fabs_test_dbl_max_negative_value) {
  ck_assert_double_eq_tol(s21_fabs(-DBL_MAX), fabs(-DBL_MAX), 1E-6);
}
END_TEST

START_TEST(fabs_test_zero_value) {
  ck_assert_double_eq_tol(s21_fabs(0.), fabs(0.), 1E-6);
}
END_TEST

START_TEST(fabs_test_nezero_value) {
  ck_assert_double_eq_tol(s21_fabs(-0.), fabs(-0.), 1E-6);
}
END_TEST

Suite *suite_fabs(void) {
  Suite *suite = suite_create("\033[30;43m S21_FABS \033[0m");
  TCase *tcase = tcase_create("tcase_fabs");
  tcase_add_test(tcase, fabs_test_normal_values);
  tcase_add_test(tcase, fabs_test_pi_value);
  tcase_add_test(tcase, fabs_test_nan_value);
  tcase_add_test(tcase, fabs_test_inf_positive_value);
  tcase_add_test(tcase, fabs_test_inf_negative_value);
  tcase_add_test(tcase, fabs_test_dbl_max_value);
  tcase_add_test(tcase, fabs_test_dbl_max_negative_value);
  tcase_add_test(tcase, fabs_test_zero_value);
  tcase_add_test(tcase, fabs_test_nezero_value);
  suite_add_tcase(suite, tcase);
  return suite;
}