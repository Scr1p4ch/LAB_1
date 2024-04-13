#include <stdio.h>
#include <stdlib.h>

#include "includes/matrix_func.h"
#include "includes/error_types.h"

extern int error_code;

matrix_struct* matrix_create(field_info* elem_type, int rows, void* data)
{
    matrix_struct* matrix = (matrix_struct* )malloc(sizeof(matrix_struct));
    
    if(NULL == matrix)
    {
        return NULL;
    }

    matrix->rows = rows;
    matrix->elements = data;
    matrix->elems_type = elem_type;

    return matrix;
}

void matrix_free(matrix_struct* matrix)
{
    free(matrix->elements);
    matrix->rows = 0;
    matrix->elems_type = NULL;
    free(matrix);
}

void matrix_sum(matrix_struct* res, matrix_struct* matrix_1, matrix_struct* matrix_2)
{
    if(matrix_1->rows == matrix_2->rows && matrix_1->elems_type == matrix_2->elems_type)
    {
        size_t elem_size = matrix_1->elems_type->elem_size;
        int rows = matrix_1->rows;

        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < rows; ++j)
            {
                matrix_1->elems_type->elem_sum((void* )((char* )res->elements + i * rows * elem_size + j * elem_size),
                     (void* )((char* )matrix_1->elements + i * rows * elem_size + j * elem_size),
                         (void* )((char* )matrix_2->elements + i * rows * elem_size + j * elem_size));
            }
        }
    }

    else if (matrix_1->rows != matrix_2->rows)
    {
        error_set(MATRICES_SIZE, &error_code);
    }
    else if (matrix_1->elems_type != matrix_2->elems_type)
    {
        error_set(ELEM_TYPE, &error_code);
    }
    
}

void matrix_prod(matrix_struct* res, const matrix_struct* matrix_1, const matrix_struct* matrix_2)
{
    if(matrix_1->rows == matrix_2->rows && matrix_1->elems_type == matrix_2->elems_type)
    {
        size_t elem_size = matrix_1->elems_type->elem_size;
        int rows = matrix_1->rows;

        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < rows; ++j)
            {            
                for(int k = 0; k < rows; ++k)
                {
                    matrix_1->elems_type->elem_prod_sum((void* )((char* )res->elements + i * rows * elem_size + j * elem_size),
                     (void* )((char* )matrix_1->elements + i * rows * elem_size + k * elem_size),
                         (void* )((char* )matrix_2->elements + k * rows * elem_size + j * elem_size));
                }
            }
        }
    }

    else if (matrix_1->rows != matrix_2->rows)
    {
        error_set(MATRICES_SIZE, &error_code);
    }
    else if (matrix_1->elems_type != matrix_2->elems_type)
    {
        error_set(ELEM_TYPE, &error_code);
    }
}

void matrix_multi_by_scalar(matrix_struct* res, const matrix_struct* matrix_1, int* scalar)
{
    size_t elem_size = matrix_1->elems_type->elem_size;
    int rows = matrix_1->rows;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            matrix_1->elems_type->elem_multi_by_scalar((void* )((char* )res->elements + i * rows * elem_size + j * elem_size),
                     (void* )((char* )matrix_1->elements + i * rows * elem_size + j * elem_size),
                         scalar);
        }
    }
}

void matrix_print(matrix_struct* matrix)
{
    size_t elem_size = matrix->elems_type->elem_size;
    int rows = matrix->rows;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            matrix->elems_type->elem_print((void* )((char*) matrix->elements + i * rows * elem_size + j * elem_size));
        }
        putchar('\n');
    }
    putchar('\n');
}