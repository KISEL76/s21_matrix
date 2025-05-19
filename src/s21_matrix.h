// +-------------------------------------------------+
// |        Code Authored by Vladimir Kiselev        |
// |                Year: 2024                       |
// |      > Syntax: Approved | Logic: Verified       |
// +-------------------------------------------------+

#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// compare output
#define SUCCESS 1
#define FAILURE 0

// reuslt output
enum { OK = 0, INCORRECT_MATRIX = 1, CALC_ERROR = 2 };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// base
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// compare
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// arithmetic
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// other
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// helpers
int s21_is_empty(matrix_t *A);
void s21_get_minor(int row, int column, matrix_t *A, matrix_t *result);
double s21_calc_det(matrix_t *A);

#endif
