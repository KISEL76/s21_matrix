#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (!s21_is_Empty(A)) {
    error = s21_create_matrix(A->columns, A->rows, result);
    if (!s21_is_Empty(result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else {
    error = INCORRECT_MATRIX;
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  *result = 0;
  int error = OK;
  if (!s21_is_Empty(A)) {
    if (A->rows == A->columns) {
      *result = s21_calc_det(A);
    } else {
      error = CALC_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX;
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;

  if (!s21_is_Empty(A)) {
    double det = 0;
    err = s21_determinant(A, &det);
    if (!err && det != 0) {
      matrix_t temp_matrix = {0}, temp_matrix_2 = {0};
      err = s21_calc_complements(A, &temp_matrix);
      if (!err) err = s21_transpose(&temp_matrix, &temp_matrix_2);
      if (!err) err = s21_mult_number(&temp_matrix_2, 1.0 / det, result);
      s21_remove_matrix(&temp_matrix);
      s21_remove_matrix(&temp_matrix_2);
    } else {
      err = (det == 0) ? 2 : err;
    }
  } else {
    err = INCORRECT_MATRIX;
  }

  return err;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (!s21_is_Empty(A)) {
    if (A->columns == A->rows && A->columns != 1) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor = {0};
          double det = 0;
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          s21_get_minor(i, j, A, &minor);
          s21_determinant(&minor, &det);
          result->matrix[i][j] = pow(-1, (i + j)) * det;
          s21_remove_matrix(&minor);
        }
      }
    } else {
      error = CALC_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}
