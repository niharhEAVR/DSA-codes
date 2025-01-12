#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size; // memory to be reserved
    int used_size;  // memory that actually used
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));
    printf("a = %d\n",a);

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
    printf("*ptr = %d\n",(int *)malloc(tSize * sizeof(int)));
}

void setValue(struct myArray *a ){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the values of the array: ");
        scanf("%d",&((a->ptr)[i]));
    }
}

void showValue(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ",(a->ptr)[i]);
    }
    
}

int main()
{
    struct myArray marks;
    printf("sizeof marks array: %d\n",sizeof(marks));
    printf("address od marks = %d\n",&marks);
    createArray(&marks, 10, 4);
    setValue(&marks);
    showValue(&marks);
    return 0;
}