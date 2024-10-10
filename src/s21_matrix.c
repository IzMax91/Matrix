#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = 0;

  if (rows > 0 && columns > 0 && result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));

    if (result->matrix != NULL) {
      for (int i = 0; i < rows && !error_code; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));

        if (result->matrix[i] == NULL) {
          error_code = 1;
        }
      }

    } else
      error_code = 1;
  } else {
    error_code = 1;
  }

  return error_code;
}

void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }

    A->rows = 0.0;
    A->columns = 0.0;

    free(A->matrix);
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int answer = SUCCESS;

  if (!correct_matrix(*A) && !correct_matrix(*B) &&
      !eq_rows_and_columns(*A, *B)) {
    double special_number = pow(10, -7);

    for (int i = 0; i < A->rows && answer; i++) {
      for (int j = 0; j < A->columns && answer; j++) {
        double difference = fabs(A->matrix[i][j] - B->matrix[i][j]);

        if (special_number < difference) {
          answer = FAILURE;
        }
      }
    }

  } else {
    answer = FAILURE;
  }

  return answer;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = sum_and_sub(A, B, result, '+');
  return error_code;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = sum_and_sub(A, B, result, '-');
  return error_code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = 0;

  if (!correct_matrix(*A)) {
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      error_code = 1;
    }
  } else {
    error_code = 1;
  }

  return error_code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = 0;

  if (!correct_matrix(*A) && !correct_matrix(*B)) {
    if (A->columns == B->rows) {
      if (!s21_create_matrix(A->rows, B->columns, result)) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = multiplication_result(*A, *B, i, j);
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

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = 0;

  if (!correct_matrix(*A)) {
    if (!s21_create_matrix(A->columns, A->rows, result)) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    } else {
      error_code = 1;
    }
  } else {
    error_code = 1;
  }

  return error_code;
}

int s21_determinant(matrix_t *A, double *result) {
  int error_code = 0;

  if (!correct_matrix(*A)) {
    if (A->rows == A->columns) {
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else {
        matrix_t new_mat;

        if (!s21_create_matrix(A->rows - 1, A->columns - 1, &new_mat)) {
          *result = 0;

          for (int j = 0; j < A->columns; j++) {
            new_matrex(A, &new_mat, 0, j);

            double num = 0.0;
            s21_determinant(&new_mat, &num);
            *result += pow(-1, j) * A->matrix[0][j] * num;
          }
          s21_remove_matrix(&new_mat);
        }

        else {
          error_code = 1;
        }
      }
    } else {
      error_code = 2;
    }
  } else {
    error_code = 1;
  }

  return error_code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = 0;

  if (!correct_matrix(*A)) {
    if (A->rows == A->columns) {
      if (s21_create_matrix(A->rows, A->columns, result)) {
        error_code = 1;
      }
    } else {
      error_code = 2;
    }
  } else {
    error_code = 1;
  }

  if (!error_code) {
    if (A->rows == 1) {
      result->matrix[0][0] = A->matrix[0][0];

    } else {
      matrix_t new_mat;
      if (!s21_create_matrix(A->rows - 1, A->columns - 1, &new_mat)) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            new_matrex(A, &new_mat, i, j);

            s21_determinant(&new_mat, &result->matrix[i][j]);
            result->matrix[i][j] *= pow(-1, i + j);
          }
        }

        s21_remove_matrix(&new_mat);
      } else {
        error_code = 1;
      }
    }
  }
  return error_code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = 0;
  double determinant = 0.0;

  if (!correct_matrix(*A)) {
    if (A->rows == A->columns) {
      s21_determinant(A, &determinant);
      if (determinant == 0) {
        error_code = 2;
      }
    } else {
      error_code = 2;
    }
  } else {
    error_code = 1;
  }

  if (!error_code) {
    matrix_t new_mat;
    s21_transpose(A, &new_mat);
    matrix_t new_mat_2;
    s21_calc_complements(&new_mat, &new_mat_2);
    s21_mult_number(&new_mat_2, 1.0 / determinant, result);

    s21_remove_matrix(&new_mat);
    s21_remove_matrix(&new_mat_2);
  }

  return error_code;
}
