// Question 7: What is the time complexity of the following snippet of code?

int isPrime(int n)
{
    for (int i = 2; i * i < 10000; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
 
    return 1;
}
isPrime();