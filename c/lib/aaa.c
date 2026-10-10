// AAA stands for An Actual Array btw lol
// also lowk useless?????
// - useless because i want this benchmark to be as optimize as possible
// i made this library to pratice memory management

#include <stdio.h>
#include <stdlib.h>
#include "aaa.h"

void init(an_actual_array *array)
{
    array->size = 0;
    array->current_cap = 8;
    array->array = malloc(8 * sizeof(int));
    if (!array->array) {
        printf("failed to alocate memory");
        free(array->array);
        free(array);
        exit(1);
    }
}

an_actual_array newArray()
{
    int* pseudo_array = malloc(8 * sizeof(int));
    if (!pseudo_array) {
        printf("failed to alocate memory");
        free(pseudo_array);
        exit(1);
    }

    an_actual_array new = {0, 8, pseudo_array};

    return new;
}

void appendInt(an_actual_array *array, int item)
{
    if (array->size == array->current_cap)
    {
        array->current_cap <<= 1;
        array->array = realloc(array->array, array->current_cap * sizeof(int));
        if (!array->array) {
            printf("failed to alocate memory");
            free(array->array);
            free(array);
            exit(1);
        }
    }
    array->size++;
    array->array[array->size] = item;
}

int getItem(an_actual_array *array, int index) {
    // git credential test 2
}