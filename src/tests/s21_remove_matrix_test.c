#include "tests.h"

START_TEST(s21_remove_matrix_test_1) {
  matrix_t mat_1;
  int rows_mat_1 = 20;
  int columns_mat_1 = 20;
  s21_create_matrix(rows_mat_1, columns_mat_1, &mat_1);
  s21_remove_matrix(&mat_1);

  ck_assert_ptr_null(mat_1.matrix);

  matrix_t mat_2;
  int rows_mat_2 = 5;
  int columns_mat_2 = 20;
  s21_create_matrix(rows_mat_2, columns_mat_2, &mat_2);
  s21_remove_matrix(&mat_2);

  ck_assert_ptr_null(mat_2.matrix);

  matrix_t mat_3;
  int rows_mat_3 = 5;
  int columns_mat_3 = 1;
  s21_create_matrix(rows_mat_3, columns_mat_3, &mat_3);
  s21_remove_matrix(&mat_3);

  ck_assert_ptr_null(mat_2.matrix);
}
END_TEST

Suite *s21_remove_matrix_test() {
  Suite *s;
  TCase *tc_remove_matrix_test_1;

  s = suite_create("s21_remove_matrix");

  tc_remove_matrix_test_1 = tcase_create("s21_remove_matrix_test_1");
  tcase_add_test(tc_remove_matrix_test_1, s21_remove_matrix_test_1);
  suite_add_tcase(s, tc_remove_matrix_test_1);

  return s;
}