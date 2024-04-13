#ifndef MATRIX_FUNC_H
#define MATRIX_FUNC_H
#define max_elem(x, y) (((x) >= (y)) ? (x) : (y))

#include "matrix_struct.h"


matrix_struct* matrix_create(field_info* elem_type, int rows, void* data);


void matrix_free(matrix_struct* matrix);

void matrix_sum(matrix_struct* res, matrix_struct* matrix_1, matrix_struct* matrix_2);

void matrix_prod(matrix_struct* res, const matrix_struct* matrix_1, const matrix_struct* matrix_2);

void matrix_print(matrix_struct* matrix);

void matrix_multi_by_scalar(matrix_struct* res, const matrix_struct* matrix_1, int* scalar);

#endif
