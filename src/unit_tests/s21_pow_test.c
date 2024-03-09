#include "s21_math_test.h"

START_TEST(pow_test_normal_values) {
  for (double x = 0.1; x < 10; x += 0.353531) {
    for (double y = 1.1; y < 10; y += 1.32542) {
      ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), 1E-6);
    }
  }
  for (double x = -10; x < -1; x += 0.343532) {
    for (double y = 1; y < 10; y += 1) {
      ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), 1E-6);
    }
  }
  for (double x = -10; x < -1; x += 0.345322) {
    for (double y = -10; y < -1; y += 1) {
      ck_assert_double_eq_tol(s21_pow(x, y), pow(x, y), 1E-6);
    }
  }
}
END_TEST

START_TEST(pow_test_exp_nan_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_nan(s21_pow(x, S21_NAN));
  }
}
END_TEST

START_TEST(pow_test_exp_inf_positive_value) {
  ck_assert_double_eq(s21_pow(-10, S21_INF_PLUS), pow(-10, S21_INF_PLUS));
  ck_assert_double_eq(s21_pow(-1, S21_INF_PLUS), pow(-1, S21_INF_PLUS));
  ck_assert_double_eq(s21_pow(-0.1, S21_INF_PLUS), pow(-0.1, S21_INF_PLUS));

  ck_assert_double_eq(s21_pow(0.1, S21_INF_PLUS), pow(0.1, S21_INF_PLUS));
  ck_assert_double_eq(s21_pow(1, S21_INF_PLUS), pow(1, S21_INF_PLUS));
  ck_assert_double_eq(s21_pow(10, S21_INF_PLUS), pow(10, S21_INF_PLUS));
}
END_TEST

START_TEST(pow_test_exp_inf_negative_value) {
  ck_assert_double_eq(s21_pow(-10, S21_INF_MINUS), pow(-10, S21_INF_MINUS));
  ck_assert_double_eq(s21_pow(-1, S21_INF_MINUS), pow(-1, S21_INF_MINUS));
  ck_assert_double_eq(s21_pow(-0.1, S21_INF_MINUS), pow(-0.1, S21_INF_MINUS));

  ck_assert_double_eq(s21_pow(0.1, S21_INF_MINUS), pow(0.1, S21_INF_MINUS));
  ck_assert_double_eq(s21_pow(1, S21_INF_MINUS), pow(1, S21_INF_MINUS));
  ck_assert_double_eq(s21_pow(10, S21_INF_MINUS), pow(10, S21_INF_MINUS));
}
END_TEST

START_TEST(pow_test_exp_zero_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq_tol(s21_pow(x, 0.), pow(x, 0.), 1E-6);
  }
}
END_TEST

START_TEST(pow_test_exp_nezero_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq_tol(s21_pow(x, -0.), pow(x, -0.), 1E-6);
  }
}
END_TEST

START_TEST(pow_test_base_nan_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_nan(s21_pow(S21_NAN, x));
  }
}
END_TEST

START_TEST(pow_test_base_inf_positive_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq(s21_pow(S21_INF_PLUS, x), pow(S21_INF_PLUS, x));
  }
}
END_TEST

START_TEST(pow_test_base_inf_negative_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq(s21_pow(S21_INF_PLUS, x), pow(S21_INF_PLUS, x));
  }
}
END_TEST

START_TEST(pow_test_base_dbl_max_value) {
  ck_assert_double_eq(s21_pow(DBL_MAX, -10), pow(DBL_MAX, -10));
  ck_assert_double_eq(s21_pow(DBL_MAX, -1), pow(DBL_MAX, -1));

  ck_assert_double_eq(s21_pow(DBL_MAX, 10), pow(DBL_MAX, 10));
  ck_assert_double_eq(s21_pow(DBL_MAX, 1), pow(DBL_MAX, 1));
}
END_TEST

START_TEST(pow_test_base_zero_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq(s21_pow(0., x), pow(0., x));
  }
}
END_TEST

START_TEST(pow_test_base_exp_nan_value) {
  ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(pow_test_base_exp_inf_positive_value) {
  ck_assert_double_eq(s21_pow(S21_INF_PLUS, S21_INF_PLUS),
                      pow(S21_INF_PLUS, S21_INF_PLUS));
}
END_TEST

START_TEST(pow_test_base_exp_inf_negative_value) {
  ck_assert_double_eq(s21_pow(S21_INF_MINUS, S21_INF_MINUS),
                      pow(S21_INF_MINUS, S21_INF_MINUS));
}
END_TEST

START_TEST(pow_test_base_exp_zero_value) {
  ck_assert_double_eq_tol(s21_pow(0., 0.), pow(0., 0.), 1E-6);
}
END_TEST

START_TEST(pow_test_base_exp_nezero_value) {
  ck_assert_double_eq_tol(s21_pow(-0., -0.), pow(-0., -0.), 1E-6);
}
END_TEST

Suite *suite_pow(void) {
  Suite *suite = suite_create("\033[30;43m S21_POW \033[0m");
  TCase *tcase = tcase_create("tcase_pow");
  tcase_add_test(tcase, pow_test_normal_values);
  tcase_add_test(tcase, pow_test_exp_nan_value);
  tcase_add_test(tcase, pow_test_exp_inf_positive_value);
  tcase_add_test(tcase, pow_test_exp_inf_negative_value);
  tcase_add_test(tcase, pow_test_exp_zero_value);
  tcase_add_test(tcase, pow_test_exp_nezero_value);
  tcase_add_test(tcase, pow_test_base_nan_value);
  tcase_add_test(tcase, pow_test_base_inf_positive_value);
  tcase_add_test(tcase, pow_test_base_inf_negative_value);
  tcase_add_test(tcase, pow_test_base_dbl_max_value);
  tcase_add_test(tcase, pow_test_base_zero_value);
  tcase_add_test(tcase, pow_test_base_exp_nan_value);
  tcase_add_test(tcase, pow_test_base_exp_inf_positive_value);
  tcase_add_test(tcase, pow_test_base_exp_inf_negative_value);
  tcase_add_test(tcase, pow_test_base_exp_zero_value);
  tcase_add_test(tcase, pow_test_base_exp_nezero_value);
  suite_add_tcase(suite, tcase);
  return suite;
}