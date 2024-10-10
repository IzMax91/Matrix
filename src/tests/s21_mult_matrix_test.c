#include "tests.h"

START_TEST(s21_mult_matrix_test_1) {
  matrix_t mat_A_1;
  int rows_mat_A_1 = 2;
  int columns_mat_A_1 = 2;

  matrix_t mat_B_1;
  int rows_mat_B_1 = 2;
  int columns_mat_B_1 = 2;

  matrix_t res_1;

  s21_create_matrix(rows_mat_A_1, columns_mat_A_1, &mat_A_1);
  mat_A_1.matrix[0][0] = 1.0;
  mat_A_1.matrix[0][1] = 2.0;
  mat_A_1.matrix[1][0] = 3.0;
  mat_A_1.matrix[1][1] = 4.0;
  s21_create_matrix(rows_mat_B_1, columns_mat_B_1, &mat_B_1);
  mat_B_1.matrix[0][0] = 1.0;
  mat_B_1.matrix[0][1] = 2.0;
  mat_B_1.matrix[1][0] = 3.0;
  mat_B_1.matrix[1][1] = 4.0;

  int error_code = s21_mult_matrix(&mat_A_1, &mat_B_1, &res_1);
  ck_assert_int_eq(error_code, 0);

  ck_assert_double_eq(res_1.matrix[0][0], 7.0);
  ck_assert_double_eq(res_1.matrix[0][1], 10.0);
  ck_assert_double_eq(res_1.matrix[1][0], 15.0);
  ck_assert_double_eq(res_1.matrix[1][1], 22.0);

  s21_remove_matrix(&mat_A_1);
  s21_remove_matrix(&mat_B_1);
  s21_remove_matrix(&res_1);

  matrix_t mat_A_2;
  int rows_mat_A_2 = 1;
  int columns_mat_A_2 = 3;

  matrix_t mat_B_2;
  int rows_mat_B_2 = 3;
  int columns_mat_B_2 = 1;

  matrix_t res_2;

  s21_create_matrix(rows_mat_A_2, columns_mat_A_2, &mat_A_2);
  mat_A_2.matrix[0][0] = 78.0;
  mat_A_2.matrix[0][1] = 85.0;
  mat_A_2.matrix[0][2] = 42.0;
  s21_create_matrix(rows_mat_B_2, columns_mat_B_2, &mat_B_2);
  mat_B_2.matrix[0][0] = 1.0;
  mat_B_2.matrix[1][0] = 2.0;
  mat_B_2.matrix[2][0] = 3.0;

  error_code = s21_mult_matrix(&mat_A_2, &mat_B_2, &res_2);
  ck_assert_int_eq(error_code, 0);

  ck_assert_double_eq(res_2.matrix[0][0], 374.0);

  s21_remove_matrix(&mat_A_2);
  s21_remove_matrix(&mat_B_2);
  s21_remove_matrix(&res_2);

  matrix_t mat_A_3;
  int rows_mat_A_3 = 2;
  int columns_mat_A_3 = 2;

  matrix_t mat_B_3;
  int rows_mat_B_3 = 2;
  int columns_mat_B_3 = 3;

  matrix_t res_3;

  s21_create_matrix(rows_mat_A_3, columns_mat_A_3, &mat_A_3);
  mat_A_3.matrix[0][0] = 13.0;
  mat_A_3.matrix[0][1] = 9.0;
  mat_A_3.matrix[1][0] = 3.0;
  mat_A_3.matrix[1][1] = 6.0;
  s21_create_matrix(rows_mat_B_3, columns_mat_B_3, &mat_B_3);
  mat_B_3.matrix[0][0] = 3.0;
  mat_B_3.matrix[0][1] = 6.0;
  mat_B_3.matrix[0][2] = 9.0;
  mat_B_3.matrix[1][0] = 12.0;
  mat_B_3.matrix[1][1] = 13.0;
  mat_B_3.matrix[1][2] = 6.0;

  error_code = s21_mult_matrix(&mat_A_3, &mat_B_3, &res_3);
  ck_assert_int_eq(error_code, 0);

  ck_assert_double_eq(res_3.matrix[0][0], 147.0);
  ck_assert_double_eq(res_3.matrix[0][1], 195.0);
  ck_assert_double_eq(res_3.matrix[0][2], 171.0);
  ck_assert_double_eq(res_3.matrix[1][0], 81.0);
  ck_assert_double_eq(res_3.matrix[1][1], 96.0);
  ck_assert_double_eq(res_3.matrix[1][2], 63.0);

  s21_remove_matrix(&mat_A_3);
  s21_remove_matrix(&mat_B_3);
  s21_remove_matrix(&res_3);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t mat_A_1;
  int rows_mat_A_1 = 2;
  int columns_mat_A_1 = 1;

  matrix_t mat_B_1;
  int rows_mat_B_1 = 2;
  int columns_mat_B_1 = 1;

  matrix_t res_1;

  s21_create_matrix(rows_mat_A_1, columns_mat_A_1, &mat_A_1);
  s21_create_matrix(rows_mat_B_1, columns_mat_B_1, &mat_B_1);

  int error_code = s21_mult_matrix(&mat_A_1, &mat_B_1, &res_1);
  ck_assert_int_eq(error_code, 2);

  s21_remove_matrix(&mat_A_1);
  s21_remove_matrix(&mat_B_1);

  matrix_t mat_A_2;
  int rows_mat_A_2 = 3;
  int columns_mat_A_2 = 3;

  matrix_t mat_B_2;
  int rows_mat_B_2 = 4;
  int columns_mat_B_2 = 4;

  matrix_t res_2;

  s21_create_matrix(rows_mat_A_2, columns_mat_A_2, &mat_A_2);
  s21_create_matrix(rows_mat_B_2, columns_mat_B_2, &mat_B_2);

  error_code = s21_mult_matrix(&mat_A_2, &mat_B_2, &res_2);
  ck_assert_int_eq(error_code, 2);

  s21_remove_matrix(&mat_A_2);
  s21_remove_matrix(&mat_B_2);

  matrix_t mat_A_3;
  int rows_mat_A_3 = 2;
  int columns_mat_A_3 = 1;

  matrix_t mat_B_3;
  mat_B_3.matrix = NULL;

  matrix_t res_3;

  s21_create_matrix(rows_mat_A_3, columns_mat_A_3, &mat_A_3);

  error_code = s21_mult_matrix(&mat_A_3, &mat_B_3, &res_3);
  ck_assert_int_eq(error_code, 1);

  s21_remove_matrix(&mat_A_3);
}
END_TEST

Suite *s21_mult_matrix_test() {
  Suite *s;
  TCase *tc_mult_matrix_test_1, *tc_mult_matrix_test_2;

  s = suite_create("s21_mult_matrix");

  tc_mult_matrix_test_1 = tcase_create("s21_mult_matrix_test_1");
  tcase_add_test(tc_mult_matrix_test_1, s21_mult_matrix_test_1);
  suite_add_tcase(s, tc_mult_matrix_test_1);

  tc_mult_matrix_test_2 = tcase_create("s21_mult_matrix_test_2");
  tcase_add_test(tc_mult_matrix_test_2, s21_mult_matrix_test_2);
  suite_add_tcase(s, tc_mult_matrix_test_2);

  return s;
}