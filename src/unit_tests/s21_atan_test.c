#include "s21_math_test.h"

START_TEST(atan_test_normal_values) {
  for (double x = -1; x <= 1; x += 0.0625) {
    ck_assert_double_eq_tol(s21_atan(x), atan(x), 1E-6);
  }
}
END_TEST

START_TEST(atan_test_untranslated_values) {
  for (double x = -100; x < 100; x += 1.345023) {
    ck_assert_double_eq_tol(s21_atan(x), atan(x), 1E-6);
  }
}
END_TEST

START_TEST(atan_test_inf_values) {
  ck_assert_double_eq_tol(s21_atan(S21_INF_PLUS), atan(S21_INF_PLUS), 1E-6);
  ck_assert_double_eq_tol(s21_atan(S21_INF_MINUS), atan(S21_INF_MINUS), 1E-6);
}
END_TEST

START_TEST(atan_test_nan_value) { ck_assert_double_nan(s21_atan(S21_NAN)); }
END_TEST

START_TEST(atan_test_zero_value) {
  ck_assert_double_eq_tol(s21_atan(0.), atan(0.), 1E-6);
}
END_TEST

START_TEST(atan_test_nezero_value) {
  ck_assert_double_eq_tol(s21_atan(-0.), atan(-0.), 1E-6);
}
END_TEST

START_TEST(atan_test_pi_value) {
  ck_assert_double_eq_tol(s21_atan(S21_PI), atan(S21_PI), 1E-6);
}
END_TEST

Suite *suite_atan(void) {
  Suite *suite = suite_create("\033[30;43m S21_ATAN \033[0m");
  TCase *tcase = tcase_create("tcase_atan");
  tcase_add_test(tcase, atan_test_normal_values);
  tcase_add_test(tcase, atan_test_untranslated_values);
  tcase_add_test(tcase, atan_test_inf_values);
  tcase_add_test(tcase, atan_test_nan_value);
  tcase_add_test(tcase, atan_test_zero_value);
  tcase_add_test(tcase, atan_test_nezero_value);
  tcase_add_test(tcase, atan_test_pi_value);
  suite_add_tcase(suite, tcase);
  return suite;
}