#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "includes/complex_func.h"
#include "includes/complex_number.h"
#include "includes/error_types.h"
#include "includes/field_info.h"
#include "includes/int_func.h"
#include "includes/matrix_func.h"
#include "includes/matrix_struct.h"
#include "includes/test.h"

void test_int_sum()
{
    int a = 10;
    int b = 19;
    int ans_1 = a + b;
    int ans_2=0;
    int_sum((void*)&ans_2, (void*)&a, (void*)&b);
    assert(ans_1 == ans_2);
}

void test_int_multi_by_scalar()
{
    int a = 10;
    int b = 3;
    int ans_1 = b * a;
    int ans_2 = 0;
    int_multi_by_scalar((void*)&ans_2, (void*)&a, (void*)&b);
    assert(ans_1 == ans_2);
}

void test_int_prod_sum()
{
    int a = 15;
    int b = -4;
    int ans_1 = b * a;
    int ans_2 = 0;
    int_prod_sum((void*)&ans_2, (void*)&a, (void*)&b);
    assert(ans_1 == ans_2);
}

void test_int_func()
{
    test_int_sum();
    test_int_multi_by_scalar();
    test_int_prod_sum();
}

void test_complex_sum()
{
    complex_number a = {3, 4};
    complex_number b = {6, -3};

    complex_number ans_1;
    ans_1.Re = a.Re + b.Re;
    ans_1.Im = a.Im + b.Im;

    complex_number ans_2;

    complex_sum((void*)&ans_2, (void*)&a, (void*)&b);
    assert(ans_1.Re == ans_2.Re);
    assert(ans_1.Im == ans_2.Im);
}

void test_complex_multi_by_scalar()
{
    complex_number a = {4, -8};
    int b = 9;

    complex_number ans_1;
    ans_1.Re = a.Re * b;
    ans_1.Im = a.Im * b;

    complex_number ans_2;

    complex_multi_by_scalar((void*)&ans_2, (void*)&a, (void*)&b);
    assert(ans_1.Re == ans_2.Re);
    assert(ans_1.Im == ans_2.Im);
}

void test_complex_prod_sum()
{
    complex_number a = {2, -3};
    complex_number b = {7, 2};

    complex_number ans_1;
    ans_1.Re = a.Re * b.Re - a.Im * b.Im;
    ans_1.Im = a.Re * b.Im + a.Im * b.Re;

    complex_number ans_2;

    complex_prod_sum((void*)&ans_2, (void*)&a, (void*)&b);
    assert(ans_1.Re == ans_2.Re);
    assert(ans_1.Im == ans_2.Im);
}

void test_complex_func()
{
    test_complex_sum();
    test_complex_multi_by_scalar();
    test_complex_prod_sum;

}

