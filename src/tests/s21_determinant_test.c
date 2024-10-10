#include "tests.h"

START_TEST(s21_determinant_test_1) {
  matrix_t mat_A_1;
  int rows_mat_A_1 = 3;
  int columns_mat_A_1 = 3;

  double num_1 = 0.0;

  s21_create_matrix(rows_mat_A_1, columns_mat_A_1, &mat_A_1);
  mat_A_1.matrix[0][0] = 1.0;
  mat_A_1.matrix[0][1] = 2.0;
  mat_A_1.matrix[0][2] = 3.0;
  mat_A_1.matrix[1][0] = 4.0;
  mat_A_1.matrix[1][1] = 5.0;
  mat_A_1.matrix[1][2] = 6.0;
  mat_A_1.matrix[2][0] = 7.0;
  mat_A_1.matrix[2][1] = 8.0;
  mat_A_1.matrix[2][2] = 9.0;

  int error_code = s21_determinant(&mat_A_1, &num_1);
  ck_assert_int_eq(error_code, 0);
  ck_assert_double_eq(num_1, 0.0);

  s21_remove_matrix(&mat_A_1);

  matrix_t mat_A_2;
  int rows_mat_A_2 = 2;
  int columns_mat_A_2 = 2;

  double num_2 = 0.0;

  s21_create_matrix(rows_mat_A_2, columns_mat_A_2, &mat_A_2);
  mat_A_2.matrix[0][0] = 0.0;
  mat_A_2.matrix[0][1] = 4.0;
  mat_A_2.matrix[1][0] = 5.0;
  mat_A_2.matrix[1][1] = 2.0;

  error_code = s21_determinant(&mat_A_2, &num_2);
  ck_assert_int_eq(error_code, 0);

  ck_assert_double_eq(num_2, -20.0);

  s21_remove_matrix(&mat_A_2);

  matrix_t mat_A_3;
  int rows_mat_A_3 = 1;
  int columns_mat_A_3 = 1;

  double num_3 = 0.0;

  s21_create_matrix(rows_mat_A_3, columns_mat_A_3, &mat_A_3);
  mat_A_3.matrix[0][0] = 12.3456789;

  error_code = s21_determinant(&mat_A_3, &num_3);
  ck_assert_int_eq(error_code, 0);

  ck_assert_double_eq(num_3, 12.3456789);

  s21_remove_matrix(&mat_A_3);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t mat_A_1;
  int rows_mat_A_1 = 3;
  int columns_mat_A_1 = 2;

  double num_1 = 0.0;

  s21_create_matrix(rows_mat_A_1, columns_mat_A_1, &mat_A_1);
  mat_A_1.matrix[0][0] = 1.0;
  mat_A_1.matrix[0][1] = 2.0;
  mat_A_1.matrix[1][0] = 4.0;
  mat_A_1.matrix[1][1] = 5.0;
  mat_A_1.matrix[2][0] = 7.0;
  mat_A_1.matrix[2][1] = 8.0;

  int error_code = s21_determinant(&mat_A_1, &num_1);
  ck_assert_int_eq(error_code, 2);
  ck_assert_double_eq(num_1, 0.0);

  s21_remove_matrix(&mat_A_1);

  matrix_t mat_A_2;
  mat_A_2.matrix = NULL;
  double num_2 = 0.0;

  error_code = s21_determinant(&mat_A_2, &num_2);
  ck_assert_int_eq(error_code, 1);
  ck_assert_double_eq(num_2, 0.0);

  matrix_t mat_A_3;
  int rows_mat_A_3 = 1;
  int columns_mat_A_3 = 2;

  double num_3 = 0.0;

  s21_create_matrix(rows_mat_A_3, columns_mat_A_3, &mat_A_3);
  mat_A_3.matrix[0][0] = 12.3456789;

  error_code = s21_determinant(&mat_A_3, &num_3);
  ck_assert_int_eq(error_code, 2);

  ck_assert_double_eq(num_3, 0.0);

  s21_remove_matrix(&mat_A_3);
}
END_TEST

Suite *s21_determinant_test() {
  Suite *s;
  TCase *tc_determinant_test_1, *tc_determinant_test_2;

  s = suite_create("s21_determinant");

  tc_determinant_test_1 = tcase_create("s21_determinant_test_1");
  tcase_add_test(tc_determinant_test_1, s21_determinant_test_1);
  suite_add_tcase(s, tc_determinant_test_1);

  tc_determinant_test_2 = tcase_create("s22_determinant_test_2");
  tcase_add_test(tc_determinant_test_2, s21_determinant_test_2);
  suite_add_tcase(s, tc_determinant_test_2);

  return s;
}