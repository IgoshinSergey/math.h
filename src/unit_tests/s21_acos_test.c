#include "s21_math_test.h"

START_TEST(acos_test_normal_values) {
  for (double x = -1; x <= 1; x += 0.0625) {
    ck_assert_double_eq_tol(s21_acos(x), acos(x), 1E-6);
  }
}
END_TEST

START_TEST(acos_test_untranslated_values) {
  for (double x = 2; x < 100; x += 5) {
    ck_assert_double_nan(s21_acos(x));
  }
}
END_TEST

START_TEST(acos_test_pi_value) { ck_assert_double_nan(s21_acos(S21_PI)); }
END_TEST

START_TEST(acos_test_nan_value) { ck_assert_double_nan(s21_acos(S21_NAN)); }
END_TEST

START_TEST(acos_test_inf_positive_value) {
  ck_assert_double_nan(s21_acos(S21_INF_PLUS));
}
END_TEST

START_TEST(acos_test_inf_negative_value) {
  ck_assert_double_nan(s21_acos(S21_INF_MINUS));
}
END_TEST

START_TEST(acos_test_zero_value) {
  ck_assert_double_eq_tol(s21_acos(0.), acos(0.), 1E-6);
}
END_TEST

Suite *suite_acos(void) {
  Suite *suite = suite_create("\033[30;43m S21_ACOS \033[0m");
  TCase *tcase = tcase_create("tcase_acos");
  tcase_add_test(tcase, acos_test_normal_values);
  tcase_add_test(tcase, acos_test_untranslated_values);
  tcase_add_test(tcase, acos_test_pi_value);
  tcase_add_test(tcase, acos_test_nan_value);
  tcase_add_test(tcase, acos_test_inf_positive_value);
  tcase_add_test(tcase, acos_test_inf_negative_value);
  tcase_add_test(tcase, acos_test_zero_value);
  suite_add_tcase(suite, tcase);
  return suite;
}