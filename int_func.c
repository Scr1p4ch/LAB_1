#include <stdio.h>
#include <stdlib.h>

#include "includes/int_func.h"

void int_sum(void* res, void* num_1, void* num_2)
{
    *(int* )res = *(int* )num_1 + *(int* )num_2;
}

void int_multi_by_scalar(void* res, void* num_1, void* scalar)
{
    *(int* )res = (*(int* )num_1) * (*(int* )scalar);
}

void int_prod_sum(void* res, void* num_1, void* num_2)
{
    *(int* )res += (*(int* )num_1) * (*(int* )num_2);
}

void int_print(void* num)
{
    printf("%3d ", *(int* )num);
}

field_info* create_int_info()
{
    field_info* int_info = (field_info* )malloc(sizeof(field_info));

    if(NULL == int_info)
    {
        return NULL;
    }

    int_info->elem_size = sizeof(int);
    int_info->elem_sum = &int_sum;
    int_info->elem_prod_sum = &int_prod_sum;
    int_info->elem_multi_by_scalar = &int_multi_by_scalar;
    int_info->elem_print = &int_print;

    return int_info;
}