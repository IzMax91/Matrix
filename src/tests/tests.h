#ifndef TESTS_S21_TESTS_H
#define TESTS_S21_TESTS_H

#define TEST_ARITHMETIC_OK 0
#define TEST_ARITHMETIC_BIG 1
#define TEST_ARITHMETIC_SMALL 2
#define TEST_ARITHMETIC_ZERO_DIV 3

#include <check.h>
#include <limits.h>

#include "../s21_matrix.h"

Suite *s21_create_matrix_test(void);
Suite *s21_remove_matrix_test(void);
Suite *s21_eq_matrix_test(void);
Suite *s21_sum_matrix_test(void);
Suite *s21_sub_matrix_test(void);
Suite *s21_mult_number_test(void);
Suite *s21_mult_matrix_test(void);
Suite *s21_transpose_test(void);
Suite *s21_determinant_test(void);
Suite *s21_calc_complements_test(void);
Suite *s21_inverse_matrix_test(void);

#endif  // TESTS_S21_TESTS_H
