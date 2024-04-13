#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "includes/matrix_struct.h"
#include "includes/matrix_func.h"
#include "includes/complex_func.h"
#include "includes/int_func.h"
#include "includes/error_types.h"
#include "includes/ui.h"
#include "includes/test.h"


int error_code = 0;

int main(void)
{

    test_int_func();
    test_complex_func();

    field_info* int_field_info = create_int_info();
    field_info* complex_field_info = create_complex_info();

    if(NULL == int_field_info)
        error_set(LOW_MEMORY, &error_code);

    if(NULL == complex_field_info)
        error_set(LOW_MEMORY, &error_code);

    char control = 0;

    start_menu();

    scanf("%d", &control);

    while(0 != control && 0 == error_code)
    {
        if(1 == control)
        {
            int rows_1;
            rows_number(&rows_1);

            int* ptr_1;
            enter_int_elems(&ptr_1, rows_1);

            int rows_2;
            rows_number(&rows_2);

            int* ptr_2;
            enter_int_elems(&ptr_2, rows_2);

            matrix_struct* m1;
            matrix_struct* m2;

            m1 = matrix_create(int_field_info, rows_1, ptr_1);
            m2 = matrix_create(int_field_info, rows_2, ptr_2);

            matrix_print(m1);
            matrix_print(m2);

            int rows_3 = max_elem(rows_1, rows_2);

            int* ptr_3;
            enter_res_ptr(&ptr_3, rows_3);

            matrix_struct* m3 = matrix_create(int_field_info, rows_3, ptr_3);

            matrix_sum(m3, m1, m2);

            printf("result\n");
            matrix_print(m3);

            matrix_free(m1);
            matrix_free(m2);
            matrix_free(m3);
        }

        else if(2 == control)
        {
            int rows_1;
            rows_number(&rows_1);

            int* ptr_1;
            enter_int_elems(&ptr_1, rows_1);

            int rows_2;
            rows_number(&rows_2);

            int* ptr_2;
            enter_int_elems(&ptr_2, rows_2);

            matrix_struct* m1;
            matrix_struct* m2;

            m1 = matrix_create(int_field_info, rows_1, ptr_1);
            m2 = matrix_create(int_field_info, rows_2, ptr_2);

            matrix_print(m1);
            matrix_print(m2);

            int rows_3 = max_elem(rows_1, rows_2);

            int* ptr_3;
            enter_res_ptr(&ptr_3, rows_3);

            matrix_struct* m3 = matrix_create(int_field_info, rows_3, ptr_3);

            matrix_prod(m3, m1, m2);

            matrix_print(m3);

            matrix_free(m1);
            matrix_free(m2);
            printf("result\n");
            matrix_free(m3);
        }

        else if(3 == control)
        {
            int rows_1;
            rows_number(&rows_1);

            int* ptr_1;
            enter_int_elems(&ptr_1, rows_1);
       
            matrix_struct* m1;
            m1 = matrix_create(int_field_info, rows_1, ptr_1);

            int scalar;
            printf("enter the number\n");
            scanf("%d", &scalar);

            int rows_3 = rows_1;

            int* ptr_3;
            enter_res_ptr(&ptr_3, rows_3);

            matrix_struct* m3 = matrix_create(int_field_info, rows_3, ptr_3);

            matrix_multi_by_scalar(m3, m1, &scalar);

            matrix_print(m1);

            printf("your number is: %d\n\n", scalar);

            printf("result\n");
            matrix_print(m3);

            matrix_free(m1);
            matrix_free(m3);
        }

        else if(4 == control)
        {
            int rows_1;
            rows_number(&rows_1);

            complex_number* ptr_1;
            enter_complex_elems(&ptr_1, rows_1);

            int rows_2;
            rows_number(&rows_2);

            complex_number* ptr_2;
            enter_complex_elems(&ptr_2, rows_2);

            matrix_struct* m1;
            matrix_struct* m2;

            m1 = matrix_create(complex_field_info, rows_1, ptr_1);
            m2 = matrix_create(complex_field_info, rows_2, ptr_2);

            matrix_print(m1);
            matrix_print(m2);

            int rows_3 = max_elem(rows_1, rows_2);

            complex_number* ptr_3;
            enter_res_complex_elems(&ptr_3, rows_3);

            matrix_struct* m3 = matrix_create(complex_field_info, rows_3, ptr_3);

            matrix_sum(m3, m1, m2);

            printf("result\n");
            matrix_print(m3);

            matrix_free(m1);
            matrix_free(m2);
            matrix_free(m3);
        }

        else if(5 == control)
        {
            int rows_1;
            rows_number(&rows_1);

            complex_number* ptr_1;
            enter_complex_elems(&ptr_1, rows_1);

            int rows_2;
            rows_number(&rows_2);

            complex_number* ptr_2;
            enter_complex_elems(&ptr_2, rows_2);

            matrix_struct* m1;
            matrix_struct* m2;

            m1 = matrix_create(complex_field_info, rows_1, ptr_1);
            m2 = matrix_create(complex_field_info, rows_2, ptr_2);

            matrix_print(m1);
            matrix_print(m2);

            int rows_3 = max_elem(rows_1, rows_2);

            complex_number* ptr_3;
            enter_res_complex_elems(&ptr_3, rows_3);

            matrix_struct* m3 = matrix_create(complex_field_info, rows_3, ptr_3);

            matrix_prod(m3, m1, m2);

            printf("result\n");
            matrix_print(m3);

            matrix_free(m1);
            matrix_free(m2);
            matrix_free(m3);
        }

        else if(6 == control)
        {
            int rows_1;
            rows_number(&rows_1);

            complex_number* ptr_1;
            enter_complex_elems(&ptr_1, rows_1);

            matrix_struct* m1;

            m1 = matrix_create(complex_field_info, rows_1, ptr_1);

            int scalar;
            printf("enter the number\n");
            scanf("%d", &scalar);

            matrix_print(m1);

            int rows_3 = rows_1;

            complex_number* ptr_3;
            enter_res_complex_elems(&ptr_3, rows_3);

            matrix_struct* m3 = matrix_create(complex_field_info, rows_3, ptr_3);

            matrix_multi_by_scalar(m3, m1, &scalar);

            printf("result\n");
            matrix_print(m3);

            matrix_free(m1);
            matrix_free(m3);
        }

        start_menu();
        scanf("%d", &control);

    }


    free(int_field_info);
    free(complex_field_info);

    return 0;
}