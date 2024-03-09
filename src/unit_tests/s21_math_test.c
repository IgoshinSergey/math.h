#include "s21_math_test.h"

void run_testcase(Suite *testcase) {
  SRunner *suite_runner = srunner_create(testcase);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);

  srunner_free(suite_runner);
}

void run_tests(void) {
  printf("\n\033[30;43m -=S21_MATH_TESTS=- \033[0m\n");
  Suite *case_list[] = {suite_abs(),   suite_fabs(), suite_fmod(), suite_ceil(),
                        suite_floor(), suite_sqrt(), suite_exp(),  suite_log(),
                        suite_pow(),   suite_acos(), suite_asin(), suite_atan(),
                        suite_cos(),   suite_sin(),  suite_tan(),  NULL};
  for (Suite **cur_test_case = case_list; *cur_test_case != NULL;
       cur_test_case++) {
    run_testcase(*cur_test_case);
  }
}

int main() {
  run_tests();
  return 0;
}