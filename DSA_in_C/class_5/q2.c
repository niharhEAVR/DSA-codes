// Question 2: Find the time complexity of the func function in the program from program2.c as follows:

void func(int n)
{
    int sum=0;
    int product =1;
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d , %d\n", i,j);
        }
    }
}
