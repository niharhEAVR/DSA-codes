#include <stdio.h>
int main()
{
    int n1, n2, n3, max,lcm;
    printf("Enter 1st positive integers: \n");
    scanf("%d", &n1);
    printf("Enter 2nd positive integers: \n");
    scanf("%d", &n2);
    printf("Enter 3rd positive integers: \n");
    scanf("%d", &n3);

    if(n1>n2){
        if(n1>n3){
            max = n1;
        } else{
            max = n3;
        }
    } else{
        if (n2>n3)
        {
            max = n2;
        }else{
            max = n3;
        }
    }

    for (lcm = max; ; lcm += max) {
        if (lcm % n1 == 0 && lcm % n2 == 0 && lcm % n3 == 0) {
            printf("LCM of %d, %d, and %d is %d\n", n1, n2, n3, lcm);
            break;
        }
    }
    return 0;
}