#include <stdio.h>
#include <stdlib.h>

#include "includes/error_types.h"

void error_set(int error_code, int* ptr)
{
    switch(error_code)
    {
        case MATRICES_SIZE:
            *(ptr) = MATRICES_SIZE;
            printf("The operation was not performed due to mismatch in the dimensions of the matrices\n");
            exit(1);
            break;

        case ELEM_TYPE:
            *(ptr) = ELEM_TYPE;
            printf("The operationw was not performed due to a type mismatch\n");
            exit(1);
            break;

        case LOW_MEMORY:
            *(ptr) = LOW_MEMORY;
            printf("The operation was not performed due to lack of memory\n");
            exit(1);
            break;

        default:
            break;
    }
}