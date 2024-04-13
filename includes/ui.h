#ifndef UI_H
#define UI_H

#include"complex_number.h"

void start_menu();

int rows_number(int* rows);

void enter_int_elems(int** ptr, int rows);

void enter_res_ptr(int** ptr, int rows);

void enter_complex_elems(complex_number** ptr, int rows);

void enter_res_complex_elems(complex_number** ptr, int rows);

#endif