#include "tests.h"

START_TEST(s21_create_matrix_test_1) {
  matrix_t mat_1;
  int rows_mat_1 = 20;
  int columns_mat_1 = 20;
  int error_code = s21_create_matrix(rows_mat_1, columns_mat_1, &mat_1);

  ck_assert_int_eq(error_code, 0);
  s21_remove_matrix(&mat_1);

  matrix_t mat_2;
  int rows_mat_2 = 5;
  int columns_mat_2 = 20;
  error_code = s21_create_matrix(rows_mat_2, columns_mat_2, &mat_2);

  ck_assert_int_eq(error_code, 0);
  s21_remove_matrix(&mat_2);

  matrix_t mat_3;
  int rows_mat_3 = 5;
  int columns_mat_3 = 1;
  error_code = s21_create_matrix(rows_mat_3, columns_mat_3, &mat_3);

  ck_assert_int_eq(error_code, 0);
  s21_remove_matrix(&mat_3);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  matrix_t mat_1;
  int rows_mat_1 = 0;
  int columns_mat_1 = 20;
  int error_code = s21_create_matrix(rows_mat_1, columns_mat_1, &mat_1);

  ck_assert_int_eq(error_code, 1);

  matrix_t mat_2;
  int rows_mat_2 = 5;
  int columns_mat_2 = -2;
  error_code = s21_create_matrix(rows_mat_2, columns_mat_2, &mat_2);

  ck_assert_int_eq(error_code, 1);

  int rows_mat_3 = 5;
  int columns_mat_3 = 1;
  error_code = s21_create_matrix(rows_mat_3, columns_mat_3, NULL);

  ck_assert_int_eq(error_code, 1);
}
END_TEST

Suite *s21_create_matrix_test() {
  Suite *s;
  TCase *tc_create_matrix_test_1, *tc_create_matrix_test_2;

  s = suite_create("s21_create_matrix");

  tc_create_matrix_test_1 = tcase_create("s21_create_matrix_test_1");
  tcase_add_test(tc_create_matrix_test_1, s21_create_matrix_test_1);
  suite_add_tcase(s, tc_create_matrix_test_1);

  tc_create_matrix_test_2 = tcase_create("s21_create_matrix_test_2");
  tcase_add_test(tc_create_matrix_test_2, s21_create_matrix_test_2);
  suite_add_tcase(s, tc_create_matrix_test_2);

  return s;
}