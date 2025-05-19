#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;

  if (!s21_is_Empty(A) && !s21_is_Empty(B) && A->columns == B->columns &&
      A->rows == B->rows) {
    for (int i = 0; i < A->rows && result; i++) {
      for (int j = 0; j < A->columns && result; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) result = FAILURE;
      }
    }
  } else {
    result = FAILURE;
  }
  return result;
}
