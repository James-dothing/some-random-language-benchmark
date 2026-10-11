#include <stdio.h>
#include <stdlib.h>
#include "lib/aaa.h"

int main() 
{
    an_actual_array* x = newArray();
    printf("say hello to x! it's at %p\n", x);
    appendInt(x, 67);
    appendInt(x, 67);
    appendInt(x, 67);
    appendInt(x, 68);
    appendInt(x, 67);
    appendInt(x, 67);
    appendInt(x, 67);
    appendInt(x, 69);
    appendInt(x, 67);

    debugArray(x);

    an_actual_array* y = newArray();

    printf("say hello to y! it's at %p\n", y);

    for (int i=0; i < 67; i++)
    {
        appendInt(y, i*i);
    }

    debugArray(y);

    for (int i=0; i<10;i++)
    {
        an_actual_array* v = newArray();
        for (int i=0; i<10;i++)
        {
            appendInt(v, 1);
        }
    }

    freeEveryArray();

    freeEveryArray();

    printf("i exited the program without any issue or error whatso ever");
    return 0;
}