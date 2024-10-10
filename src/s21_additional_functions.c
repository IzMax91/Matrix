#include "s21_matrix.h"

int correct_matrix(matrix_t mat) {
  int answer = 0;
  if (!mat.matrix || mat.rows <= 0 || mat.columns <= 0) {
    answer = 1;
  }

  return answer;
}

int eq_rows_and_columns(matrix_t A, matrix_t B) {
  int answer = 0;
  if (A.rows != B.rows || A.columns != B.columns) {
    answer = 1;
  }

  return answer;
}

int sum_and_sub(matrix_t *A, matrix_t *B, matrix_t *result, char sign) {
  int error_code = 0;

  if (!correct_matrix(*A) && !correct_matrix(*B)) {
    if (!eq_rows_and_columns(*A, *B)) {
      if (!s21_create_matrix(A->rows, A->columns, result)) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            if (sign == '+') {
              result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            } else if (sign == '-') {
              result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
          }
        }

      } else {
        error_code = 1;
      }
    } else {
      error_code = 2;
    }
  } else {
    error_code = 1;
  }
  return error_code;
}

double multiplication_result(matrix_t A, matrix_t B, int result_rows,
                             int result_columns) {
  double answer = 0.0;

  for (int i = 0; i < A.columns; i++) {
    answer += A.matrix[result_rows][i] * B.matrix[i][result_columns];
  }

  return answer;
}

void new_matrex(matrix_t *old_mat, matrix_t *new_mat, int row, int col) {
  for (int i = 0, new_row = 0; i < old_mat->rows; i++) {
    if (i != row) {
      for (int j = 0, new_col = 0; j < old_mat->columns; j++) {
        if (j != col) {
          new_mat->matrix[new_row][new_col++] = old_mat->matrix[i][j];
        }
      }
      new_row++;
    }
  }
}