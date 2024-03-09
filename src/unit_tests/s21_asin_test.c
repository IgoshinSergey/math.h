#include "s21_math_test.h"

START_TEST(asin_test_normal_values) {
  for (double x = -1; x <= 1; x += 0.0625) {
    ck_assert_double_eq_tol(s21_asin(x), asin(x), 1E-6);
  }
}
END_TEST

START_TEST(asin_test_untranslated_values) {
  for (double x = -1; x < 1; x += 0.039414) {
    ck_assert_double_eq_tol(s21_asin(x), asin(x), 1E-6);
    ck_assert_double_eq_tol(s21_asin(-x), asin(-x), 1E-6);
  }
}
END_TEST

START_TEST(asin_test_pi_value) { ck_assert_double_nan(s21_asin(S21_PI)); }
END_TEST

START_TEST(asin_test_nan_value) { ck_assert_double_nan(s21_asin(S21_NAN)); }
END_TEST

START_TEST(asin_test_inf_positive_value) {
  ck_assert_double_nan(s21_asin(S21_INF_PLUS));
}
END_TEST

START_TEST(asin_test_inf_negative_value) {
  ck_assert_double_nan(s21_asin(S21_INF_MINUS));
}
END_TEST

START_TEST(asin_test_zero_value) {
  ck_assert_double_eq_tol(s21_asin(0.), asin(0.), 1E-6);
}
END_TEST

START_TEST(asin_test_nezero_value) {
  ck_assert_double_eq_tol(s21_asin(-0.), asin(-0.), 1E-6);
}
END_TEST

Suite *suite_asin(void) {
  Suite *suite = suite_create("\033[30;43m S21_ASIN \033[0m");
  TCase *tcase = tcase_create("tcase_asin");
  tcase_add_test(tcase, asin_test_normal_values);
  tcase_add_test(tcase, asin_test_untranslated_values);
  tcase_add_test(tcase, asin_test_pi_value);
  tcase_add_test(tcase, asin_test_nan_value);
  tcase_add_test(tcase, asin_test_inf_positive_value);
  tcase_add_test(tcase, asin_test_inf_negative_value);
  tcase_add_test(tcase, asin_test_zero_value);
  tcase_add_test(tcase, asin_test_nezero_value);
  suite_add_tcase(suite, tcase);
  return suite;
}