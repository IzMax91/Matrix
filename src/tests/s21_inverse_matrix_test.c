#include "tests.h"

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t mat_A_1;
  int rows_mat_A_1 = 3;
  int columns_mat_A_1 = 3;

  matrix_t res_1;

  s21_create_matrix(rows_mat_A_1, columns_mat_A_1, &mat_A_1);
  mat_A_1.matrix[0][0] = 2.0;
  mat_A_1.matrix[0][1] = 5.0;
  mat_A_1.matrix[0][2] = 7.0;
  mat_A_1.matrix[1][0] = 6.0;
  mat_A_1.matrix[1][1] = 3.0;
  mat_A_1.matrix[1][2] = 4.0;
  mat_A_1.matrix[2][0] = 5.0;
  mat_A_1.matrix[2][1] = -2.0;
  mat_A_1.matrix[2][2] = -3.0;

  int error_code = s21_inverse_matrix(&mat_A_1, &res_1);
  ck_assert_int_eq(error_code, 0);

  ck_assert_double_eq(res_1.matrix[0][0], 1.0);
  ck_assert_double_eq(res_1.matrix[0][1], -1.0);
  ck_assert_double_eq(res_1.matrix[0][2], 1.0);
  ck_assert_double_eq(res_1.matrix[1][0], -38.0);
  ck_assert_double_eq(res_1.matrix[1][1], 41.0);
  ck_assert_double_eq(res_1.matrix[1][2], -34.0);
  ck_assert_double_eq(res_1.matrix[2][0], 27.0);
  ck_assert_double_eq(res_1.matrix[2][1], -29.0);
  ck_assert_double_eq(res_1.matrix[2][2], 24.0);

  s21_remove_matrix(&mat_A_1);
  s21_remove_matrix(&res_1);

  matrix_t mat_A_2;
  int rows_mat_A_2 = 2;
  int columns_mat_A_2 = 2;

  matrix_t res_2;

  s21_create_matrix(rows_mat_A_2, columns_mat_A_2, &mat_A_2);
  mat_A_2.matrix[0][0] = 3.0;
  mat_A_2.matrix[0][1] = 2.0;
  mat_A_2.matrix[1][0] = 1.0;
  mat_A_2.matrix[1][1] = -2.0;

  error_code = s21_inverse_matrix(&mat_A_2, &res_2);
  ck_assert_int_eq(error_code, 0);

  ck_assert_double_eq(res_2.matrix[0][0], 1.0 / 4.0);
  ck_assert_double_eq(res_2.matrix[0][1], 1.0 / 4.0);
  ck_assert_double_eq(res_2.matrix[1][0], 1.0 / 8.0);
  ck_assert_double_eq(res_2.matrix[1][1], -3.0 / 8.0);

  s21_remove_matrix(&mat_A_2);
  s21_remove_matrix(&res_2);

  matrix_t mat_A_3;
  int rows_mat_A_3 = 1;
  int columns_mat_A_3 = 1;

  matrix_t res_3;

  s21_create_matrix(rows_mat_A_3, columns_mat_A_3, &mat_A_3);
  mat_A_3.matrix[0][0] = 12.3456789;

  error_code = s21_inverse_matrix(&mat_A_3, &res_3);
  ck_assert_int_eq(error_code, 0);

  ck_assert_double_eq(res_3.matrix[0][0], 1.0);

  s21_remove_matrix(&mat_A_3);
  s21_remove_matrix(&res_3);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t mat_A_1;
  int rows_mat_A_1 = 3;
  int columns_mat_A_1 = 2;

  matrix_t res_1;

  s21_create_matrix(rows_mat_A_1, columns_mat_A_1, &mat_A_1);
  mat_A_1.matrix[0][0] = 1.0;
  mat_A_1.matrix[0][1] = 2.0;
  mat_A_1.matrix[1][0] = 4.0;
  mat_A_1.matrix[1][1] = 5.0;
  mat_A_1.matrix[2][0] = 7.0;
  mat_A_1.matrix[2][1] = 8.0;

  int error_code = s21_inverse_matrix(&mat_A_1, &res_1);
  ck_assert_int_eq(error_code, 2);

  s21_remove_matrix(&mat_A_1);

  matrix_t mat_A_2;
  mat_A_2.matrix = NULL;
  matrix_t res_2;

  error_code = s21_inverse_matrix(&mat_A_2, &res_2);
  ck_assert_int_eq(error_code, 1);

  matrix_t mat_A_3;
  int rows_mat_A_3 = 3;
  int columns_mat_A_3 = 3;

  matrix_t res_3;

  s21_create_matrix(rows_mat_A_3, columns_mat_A_3, &mat_A_3);
  mat_A_3.matrix[0][0] = 1.0;
  mat_A_3.matrix[0][1] = 2.0;
  mat_A_3.matrix[0][2] = 3.0;
  mat_A_3.matrix[1][0] = 4.0;
  mat_A_3.matrix[1][1] = 5.0;
  mat_A_3.matrix[1][2] = 6.0;
  mat_A_3.matrix[2][0] = 7.0;
  mat_A_3.matrix[2][1] = 8.0;
  mat_A_3.matrix[2][2] = 9.0;

  error_code = s21_inverse_matrix(&mat_A_3, &res_3);
  ck_assert_int_eq(error_code, 2);

  s21_remove_matrix(&mat_A_3);
}
END_TEST

Suite *s21_inverse_matrix_test() {
  Suite *s;
  TCase *tc_inverse_matrix_test_1, *tc_inverse_matrix_test_2;

  s = suite_create("s21_inverse_matrix");

  tc_inverse_matrix_test_1 = tcase_create("s21_inverse_matrix_test_1");
  tcase_add_test(tc_inverse_matrix_test_1, s21_inverse_matrix_test_1);
  suite_add_tcase(s, tc_inverse_matrix_test_1);

  tc_inverse_matrix_test_2 = tcase_create("s22_inverse_matrix_test_2");
  tcase_add_test(tc_inverse_matrix_test_2, s21_inverse_matrix_test_2);
  suite_add_tcase(s, tc_inverse_matrix_test_2);

  return s;
}