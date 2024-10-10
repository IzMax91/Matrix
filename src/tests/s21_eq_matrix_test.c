#include "tests.h"

START_TEST(s21_eq_matrix_test_1) {
  matrix_t mat_A_1;
  int rows_mat_A_1 = 20;
  int columns_mat_A_1 = 20;

  matrix_t mat_B_1;
  int rows_mat_B_1 = 20;
  int columns_mat_B_1 = 20;

  s21_create_matrix(rows_mat_A_1, columns_mat_A_1, &mat_A_1);
  s21_create_matrix(rows_mat_B_1, columns_mat_B_1, &mat_B_1);

  int error_code = s21_eq_matrix(&mat_A_1, &mat_B_1);
  ck_assert_int_eq(error_code, 1);

  s21_remove_matrix(&mat_A_1);
  s21_remove_matrix(&mat_B_1);

  matrix_t mat_A_2;
  int rows_mat_A_2 = 5;
  int columns_mat_A_2 = 20;

  matrix_t mat_B_2;
  int rows_mat_B_2 = 5;
  int columns_mat_B_2 = 20;

  s21_create_matrix(rows_mat_A_2, columns_mat_A_2, &mat_A_2);
  s21_create_matrix(rows_mat_B_2, columns_mat_B_2, &mat_B_2);

  error_code = s21_eq_matrix(&mat_A_2, &mat_B_2);
  ck_assert_int_eq(error_code, 1);

  s21_remove_matrix(&mat_A_2);
  s21_remove_matrix(&mat_B_2);

  matrix_t mat_A_3;
  int rows_mat_A_3 = 5;
  int columns_mat_A_3 = 1;

  matrix_t mat_B_3;
  int rows_mat_B_3 = 5;
  int columns_mat_B_3 = 1;

  s21_create_matrix(rows_mat_A_3, columns_mat_A_3, &mat_A_3);
  s21_create_matrix(rows_mat_B_3, columns_mat_B_3, &mat_B_3);

  error_code = s21_eq_matrix(&mat_A_3, &mat_B_3);
  ck_assert_int_eq(error_code, 1);

  s21_remove_matrix(&mat_A_3);
  s21_remove_matrix(&mat_B_3);

  matrix_t mat_A_4;
  int rows_mat_A_4 = 2;
  int columns_mat_A_4 = 1;

  matrix_t mat_B_4;
  int rows_mat_B_4 = 2;
  int columns_mat_B_4 = 1;

  s21_create_matrix(rows_mat_A_4, columns_mat_A_4, &mat_A_4);
  mat_A_4.matrix[0][0] = 1.234567891;
  mat_A_4.matrix[1][0] = 12.34567891;
  s21_create_matrix(rows_mat_B_4, columns_mat_B_4, &mat_B_4);
  mat_B_4.matrix[0][0] = 1.23456789;
  mat_B_4.matrix[1][0] = 12.3456789;

  error_code = s21_eq_matrix(&mat_A_4, &mat_B_4);
  ck_assert_int_eq(error_code, 1);

  s21_remove_matrix(&mat_A_4);
  s21_remove_matrix(&mat_B_4);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t mat_A_1;
  int rows_mat_A_1 = 5;
  int columns_mat_A_1 = 20;

  matrix_t mat_B_1;
  int rows_mat_B_1 = 20;
  int columns_mat_B_1 = 5;

  s21_create_matrix(rows_mat_A_1, columns_mat_A_1, &mat_A_1);
  s21_create_matrix(rows_mat_B_1, columns_mat_B_1, &mat_B_1);

  int error_code = s21_eq_matrix(&mat_A_1, &mat_B_1);
  ck_assert_int_eq(error_code, 0);

  s21_remove_matrix(&mat_A_1);
  s21_remove_matrix(&mat_B_1);

  matrix_t mat_A_2;
  int rows_mat_A_2 = 1;
  int columns_mat_A_2 = 1;

  matrix_t mat_B_2;
  int rows_mat_B_2 = 2;
  int columns_mat_B_2 = 2;

  s21_create_matrix(rows_mat_A_2, columns_mat_A_2, &mat_A_2);
  s21_create_matrix(rows_mat_B_2, columns_mat_B_2, &mat_B_2);

  error_code = s21_eq_matrix(&mat_A_2, &mat_B_2);
  ck_assert_int_eq(error_code, 0);

  s21_remove_matrix(&mat_A_2);
  s21_remove_matrix(&mat_B_2);

  matrix_t mat_A_3;
  int rows_mat_A_3 = 5;
  int columns_mat_A_3 = 1;

  matrix_t mat_B_3;
  int rows_mat_B_3 = 5;
  int columns_mat_B_3 = 2;

  s21_create_matrix(rows_mat_A_3, columns_mat_A_3, &mat_A_3);
  s21_create_matrix(rows_mat_B_3, columns_mat_B_3, &mat_B_3);

  error_code = s21_eq_matrix(&mat_A_3, &mat_B_3);
  ck_assert_int_eq(error_code, 0);

  s21_remove_matrix(&mat_A_3);
  s21_remove_matrix(&mat_B_3);

  matrix_t mat_A_4;
  int rows_mat_A_4 = 2;
  int columns_mat_A_4 = 1;

  matrix_t mat_B_4;
  int rows_mat_B_4 = 2;
  int columns_mat_B_4 = 1;

  s21_create_matrix(rows_mat_A_4, columns_mat_A_4, &mat_A_4);
  mat_A_4.matrix[0][0] = 1.234567891;
  mat_A_4.matrix[1][0] = 12.34567891;
  s21_create_matrix(rows_mat_B_4, columns_mat_B_4, &mat_B_4);
  mat_B_4.matrix[0][0] = 1.23456789;
  mat_B_4.matrix[1][0] = 12.3456799;

  error_code = s21_eq_matrix(&mat_A_4, &mat_B_4);
  ck_assert_int_eq(error_code, 0);

  s21_remove_matrix(&mat_A_4);
  s21_remove_matrix(&mat_B_4);
}
END_TEST

Suite *s21_eq_matrix_test() {
  Suite *s;
  TCase *tc_eq_matrix_test_1, *tc_eq_matrix_test_2;

  s = suite_create("s21_eq_matrix");

  tc_eq_matrix_test_1 = tcase_create("s21_eq_matrix_test_1");
  tcase_add_test(tc_eq_matrix_test_1, s21_eq_matrix_test_1);
  suite_add_tcase(s, tc_eq_matrix_test_1);

  tc_eq_matrix_test_2 = tcase_create("s21_eq_matrix_test_2");
  tcase_add_test(tc_eq_matrix_test_2, s21_eq_matrix_test_2);
  suite_add_tcase(s, tc_eq_matrix_test_2);

  return s;
}