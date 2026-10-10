#include <stdlib.h>
#ifndef AAA_H
#define AAA_H

typedef struct {
    size_t size;
    size_t current_cap;
    int* array;
}an_actual_array;

void init(an_actual_array *array);
an_actual_array newArray();
void appendInt(an_actual_array *array, int item);
int getItem(an_actual_array *array, int index);



#endif