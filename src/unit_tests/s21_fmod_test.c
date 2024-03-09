#include "s21_math_test.h"

START_TEST(fmod_test_normal_values) {
  for (double x = -100; x < 100; x += 0.345023) {
    for (double y = -100; y < 100; y += 2.125321) {
      ck_assert_double_eq_tol(s21_fmod(x, y), fmod(x, y), 1E-6);
    }
  }
}
END_TEST

START_TEST(fmod_test_y_nan_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_nan(s21_fmod(x, S21_NAN));
  }
}
END_TEST

START_TEST(fmod_test_y_inf_positive_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq(s21_fmod(x, S21_INF_PLUS), fmod(x, S21_INF_PLUS));
  }
}
END_TEST

START_TEST(fmod_test_y_inf_negative_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq(s21_fmod(x, S21_INF_PLUS), fmod(x, S21_INF_PLUS));
  }
}
END_TEST

START_TEST(fmod_test_y_dbl_max_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq(s21_fmod(x, DBL_MAX), fmod(x, DBL_MAX));
  }
}
END_TEST

START_TEST(fmod_test_x_dbl_max_negative_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq(s21_fmod(x, -DBL_MAX), fmod(x, -DBL_MAX));
  }
}
END_TEST

START_TEST(fmod_test_y_zero_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_nan(s21_fmod(x, 0.));
  }
}
END_TEST

START_TEST(fmod_test_y_nezero_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_nan(s21_fmod(x, -0.));
  }
}
END_TEST

START_TEST(fmod_test_x_nan_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_nan(s21_fmod(S21_NAN, x));
  }
}
END_TEST

START_TEST(fmod_test_x_inf_positive_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_nan(s21_fmod(S21_INF_PLUS, x));
  }
}
END_TEST

START_TEST(fmod_test_x_inf_negative_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_nan(s21_fmod(S21_INF_PLUS, x));
  }
}
END_TEST

START_TEST(fmod_test_x_zero_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq_tol(s21_fmod(0., x), fmod(0., x), 1E-6);
  }
}
END_TEST

START_TEST(fmod_test_x_nezero_value) {
  for (double x = -100; x < 100; x += 0.345023) {
    ck_assert_double_eq_tol(s21_fmod(-0., x), fmod(-0., x), 1E-6);
  }
}
END_TEST

START_TEST(fmod_test_x_y_nan_value) {
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(fmod_test_x_y_inf_positive_value) {
  ck_assert_double_nan(s21_fmod(S21_INF_PLUS, S21_INF_PLUS));
}
END_TEST

START_TEST(fmod_test_x_y_inf_negative_value) {
  ck_assert_double_nan(s21_fmod(S21_INF_MINUS, S21_INF_MINUS));
}
END_TEST

START_TEST(fmod_test_x_y_dbl_max_value) {
  ck_assert_double_eq_tol(s21_fmod(DBL_MAX, DBL_MAX), fmod(DBL_MAX, DBL_MAX),
                          1E-6);
}
END_TEST

START_TEST(fmod_test_x_y_dbl_max_negative_value) {
  ck_assert_double_eq_tol(s21_fmod(-DBL_MAX, -DBL_MAX),
                          fmod(-DBL_MAX, -DBL_MAX), 1E-6);
}
END_TEST

START_TEST(fmod_test_x_y_zero_value) { ck_assert_double_nan(s21_fmod(0., 0.)); }
END_TEST

START_TEST(fmod_test_x_y_nezero_value) {
  ck_assert_double_nan(s21_fmod(-0., -0.));
}
END_TEST

Suite *suite_fmod(void) {
  Suite *suite = suite_create("\033[30;43m S21_FMOD \033[0m");
  TCase *tcase = tcase_create("tcase_fmod");
  tcase_add_test(tcase, fmod_test_normal_values);
  tcase_add_test(tcase, fmod_test_y_nan_value);
  tcase_add_test(tcase, fmod_test_y_inf_positive_value);
  tcase_add_test(tcase, fmod_test_y_inf_negative_value);
  tcase_add_test(tcase, fmod_test_y_dbl_max_value);
  tcase_add_test(tcase, fmod_test_x_dbl_max_negative_value);
  tcase_add_test(tcase, fmod_test_y_zero_value);
  tcase_add_test(tcase, fmod_test_y_nezero_value);
  tcase_add_test(tcase, fmod_test_x_nan_value);
  tcase_add_test(tcase, fmod_test_x_inf_positive_value);
  tcase_add_test(tcase, fmod_test_x_inf_negative_value);
  tcase_add_test(tcase, fmod_test_x_zero_value);
  tcase_add_test(tcase, fmod_test_x_nezero_value);
  tcase_add_test(tcase, fmod_test_x_y_nan_value);
  tcase_add_test(tcase, fmod_test_x_y_inf_positive_value);
  tcase_add_test(tcase, fmod_test_x_y_inf_negative_value);
  tcase_add_test(tcase, fmod_test_x_y_dbl_max_value);
  tcase_add_test(tcase, fmod_test_x_y_dbl_max_negative_value);
  tcase_add_test(tcase, fmod_test_x_y_zero_value);
  tcase_add_test(tcase, fmod_test_x_y_nezero_value);
  suite_add_tcase(suite, tcase);
  return suite;
}