#include<stdio.h>
#include<string.h>

void printname(char *name){
    for (int i = 0; i < strlen(name); i++)
    {
        char ch = name[i];
        if(name[i] == 'D'){
            printf("Found D\n");
        }
    }
    
    puts(name);
}

int main()
{
    char name[] = "Nihar Debnath";
    printname(name);
    return 0;
}