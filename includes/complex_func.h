#ifndef COMPLEX_FUNC_H
#define COMPLEX_FUNC_H

#include "complex_number.h"
#include "field_info.h"

void complex_sum(void* res, void* num_1, void* num_2);

void complex_multi_by_scalar(void* res, void* num, void* scalar);

void complex_prod_sum(void* res, void* num_1, void* num_2);

void complex_print(void* num);

field_info* create_complex_info();

#endif



