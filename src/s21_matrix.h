#ifndef MATRIX_H
#define MATRIX_H

#define SUCCESS 1
#define FAILURE 0

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void filling_matrix(matrix_t mat, double num);
void print_matrix(matrix_t mat);
int correct_matrix(matrix_t mat);
int eq_rows_and_columns(matrix_t A, matrix_t B);
int sum_and_sub(matrix_t *A, matrix_t *B, matrix_t *result, char sign);
double multiplication_result(matrix_t A, matrix_t B, int result_rows,
                             int result_columns);
void new_matrex(matrix_t *old_mat, matrix_t *new_mat, int row, int col);

#endif