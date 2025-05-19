#include "../s21_matrix.h"

int s21_is_empty(matrix_t *A) {
  int output = OK;
  if (A != NULL && A->matrix != NULL && A->rows >= 1 && A->columns >= 1)
    output = OK;
  else
    output = INCORRECT_MATRIX;

  return output;
}

double s21_calc_det(matrix_t *A) {
  double flag = 0;

  if (A->rows == 1 && A->columns == 1) {
    flag = A->matrix[0][0];
  } else {
    for (int i = 0; i < A->columns; i++) {
      matrix_t temp;
      s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
      s21_get_minor(0, i, A, &temp);

      double det_temp = s21_calc_det(&temp);

      if (i % 2) {
        flag -= A->matrix[0][i] * det_temp;
      } else {
        flag += A->matrix[0][i] * det_temp;
      }

      s21_remove_matrix(&temp);
    }
  }
  return flag;
}

void s21_get_minor(int row, int column, matrix_t *A, matrix_t *result) {
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == column) {
        continue;
      }
      result->matrix[m_row][m_col] = A->matrix[i][j];
      m_col++;
    }
    m_row++;
  }
}
