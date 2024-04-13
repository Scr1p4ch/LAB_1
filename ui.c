#include <stdio.h>
#include <stdlib.h>

#include "includes/ui.h"
#include "includes/error_types.h"
#include "includes/complex_number.h"

extern int error_code;

void start_menu()
{
    printf("0. stop the program\n");
    printf("1. the sum of int_matrices\n");
    printf("2. the product of int_matrices\n");
    printf("3. multiplying a int_matrix by a scalar\n");
    printf("4. the sum of complex_matrices\n");
    printf("5. the product of complex_matrices\n");
    printf("6. multiplying a complex_matrix by a scalar\n");
}

int rows_number(int* rows)
{
    printf("enter the number of rows\n");
    scanf("%d", rows);
}

void enter_int_elems(int** ptr, int rows)
{
    *(ptr) = (int* )malloc((rows * rows) * sizeof(int));

    if(NULL == *(ptr))
    {
        error_set(LOW_MEMORY, &error_code);
    }

    printf("enter elements\n");

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            scanf("%d", (*(ptr) + i * rows + j));
        }
    }

}

void enter_res_ptr(int** ptr, int rows)
{
    *(ptr) = (int* )malloc((rows * rows) * sizeof(int));

    if(NULL == *(ptr))
    {
        error_set(LOW_MEMORY, &error_code);
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            *(*(ptr) + i * rows + j) = 0;
        }
    }
}

void enter_complex_elems(complex_number** ptr, int rows)
{
    *(ptr) = (complex_number* )malloc((rows * rows) * sizeof(complex_number));

    if(NULL == *(ptr))
    {
        error_set(LOW_MEMORY, &error_code);
    }

    printf("enter elements\n");

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            scanf("%d", &((*(ptr) + i * rows + j)->Re));
            scanf("%d", &((*(ptr) + i * rows + j)->Im));
        }
    }
}

void enter_res_complex_elems(complex_number** ptr, int rows)
{
    *(ptr) = (complex_number* )malloc((rows * rows) * sizeof(complex_number));

    if(NULL == *(ptr))
    {
        error_set(LOW_MEMORY, &error_code);
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            ((*(ptr) + i * rows + j)->Re) = 0;
            ((*(ptr) + i * rows + j)->Im) = 0;
        }
    }
}