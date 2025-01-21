#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int tsize;
    int usize;
    int *ptr;
} dma;

void createArray(dma *tempo, int _tsize, int _usize)
{
    tempo->tsize = _tsize;
    tempo->usize = _usize;
    tempo->ptr = (int *)malloc(_tsize * sizeof(int));
}

void addValue(dma *tempo, int value)
{
    if (tempo->usize >= tempo->tsize)
    {
        tempo->tsize *= 2;
        tempo->ptr = (int *)realloc(tempo->ptr, tempo->tsize * sizeof(int));
        printf("Aarray resized to: %d elements\n", tempo->tsize);
    }

    (tempo->ptr)[tempo->usize] = value;
    printf("%d is added at the index %d.\n", value, tempo->usize);
    tempo->usize++;
}

void removeValue(dma *tempo, int index)
{
    if(((tempo->tsize)/2) == tempo->usize){
        tempo->tsize /= 2;
        tempo->ptr = (int *)realloc(tempo->ptr, tempo->tsize * sizeof(int));
        printf("Aarray resized to: %d elements\n", tempo->tsize);
    }
    for (int i = index; i < (tempo->usize) - 1; i++)
    {
        (tempo->ptr)[i] = (tempo->ptr)[i + 1];
    }
    tempo->usize--;
}

void display(dma *tempo)
{
    for (int i = 0; i < tempo->usize; i++)
    {
        printf("%d ", (tempo->ptr)[i]);
    }
    printf("\n");
}

int main()
{
    dma arr;
    createArray(&arr, 5, 0);
    addValue(&arr, 10);
    addValue(&arr, 20);
    addValue(&arr, 30);
    addValue(&arr, 40);
    addValue(&arr, 50);
    addValue(&arr, 60);
    display(&arr);
    removeValue(&arr, 1);
    display(&arr);
    removeValue(&arr, 3);
    display(&arr);
    addValue(&arr, 70);
    addValue(&arr, 80);
    display(&arr);

    return 0;
}