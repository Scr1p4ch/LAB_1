#ifndef INT_FUNC_H
#define INT_FUNC_H

#include "field_info.h"

void int_sum(void* res, void* num_1, void* num_2);

void int_multi_by_scalar(void* res, void* num_1, void* scalar);

void int_prod_sum(void* res, void* num_1, void* num_2);

void int_print(void* num);

field_info* create_int_info();

#endif