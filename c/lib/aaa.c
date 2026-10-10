// AAA stands for An Actual Array btw lol
// made by me (james) ;D
//TO DO LIST:
//replace print with error
//remove all logs
//fix realloc memory leak at appendInt() and add_array
//make naming and formatting more consistant
//at getItem() don't make it destory the whole array
//follow the Ajkcssodf order's

#include <stdio.h>
#include <stdlib.h>
#include "aaa.h"

static array_array every_array = {0,8, NULL};

static void addArray(an_actual_array* item)
{
    if (!every_array.array)
    {
        every_array.array = malloc(8 * sizeof(an_actual_array*));
        if (!every_array.array)
        {
            printf("failed to alocate memory");
            exit(1);
        }
    }

    if (every_array.size == every_array.current_cap)
    {
        every_array.current_cap <<= 1;
        every_array.array = realloc(every_array.array, every_array.current_cap * sizeof(an_actual_array*));
        if (!every_array.array)
        {
            printf("failed to alocate memory");
            free(every_array.array);
            exit(1);
        }
    }
    every_array.array[every_array.size] = item;
    every_array.size++;
}

void freeEveryArray()
{
    if (every_array.array)
    {
        for (size_t i=0;i < every_array.size;i++)
        {
            printf("i freed %p RAHHH\n", every_array.array[i]);
            printf("i freed %p RAHHH\n", every_array.array[i]->array);
            free(every_array.array[i]->array);
            free(every_array.array[i]);
            every_array.array[i] = NULL;
        }
        every_array.size = 0;
    }
}

an_actual_array* newArray()
{
    int* pseudo_array = malloc(8 * sizeof(int));
    if (!pseudo_array)
    {
        printf("failed to alocate memory");
        free(pseudo_array);
        exit(1);
    }

    an_actual_array* new = malloc(sizeof(an_actual_array)); //incease life time :mindblowing_face:
    if (!new)
    {
        free(new);
        free(pseudo_array);
        exit(1);
    }
    *new = (an_actual_array){0, 8, pseudo_array};
    addArray(new);
    return new;
}

void appendInt(an_actual_array *array, int item)
{
    if (array->size == array->current_cap)
    {
        array->current_cap <<= 1;
        array->array = realloc(array->array, array->current_cap * sizeof(int));
        if (!array->array)
        {
            printf("failed to alocate memory");
            free(array->array);
            free(array);
            exit(1);
        }
    }
    array->array[array->size] = item;
    array->size++;
}

int getItem(an_actual_array *array, int index)
{
    if (index < array->size)
    {
        return array->array[index];
    }
    printf("index out of range");
    free(array->array);
    free(array);
    exit(1);
    // git credential test 2
}

void debugArray(an_actual_array* array)
{
    printf("\nsize: %zu\n", array->size );
    printf("max size: %zu\n", array->current_cap);
    for (size_t i = 0;i<array->size;i++)
    {
        printf("%d: ", i);
        printf("%d", array->array[i]);
        printf(" ,");
    }
    printf("\n");
}