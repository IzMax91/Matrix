#include "tests.h"

int main() {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  Suite *list_cases[] = {s21_create_matrix_test(),  s21_remove_matrix_test(),
                         s21_eq_matrix_test(),      s21_sum_matrix_test(),
                         s21_sub_matrix_test(),     s21_mult_number_test(),
                         s21_mult_matrix_test(),    s21_transpose_test(),
                         s21_determinant_test(),    s21_calc_complements_test(),
                         s21_inverse_matrix_test(), NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    s = list_cases[i];
    runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
